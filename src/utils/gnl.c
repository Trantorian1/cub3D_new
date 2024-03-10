/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:44:00 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/10 18:02:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "stralloc.h"
#include "lib_strjoin.h"

#define SIZE 1024

static inline uint8_t	save_to_str(
	char *_Nonnull *_Nonnull str,
	char _Nonnull buffer[SIZE],
	size_t *_Nonnull start,
	size_t *_Nonnull stop
);
static inline uint8_t	save_to_buffer(
	uint32_t fd,
	char _Nonnull buffer[SIZE],
	size_t *_Nonnull start,
	size_t *_Nonnull stop
);
static inline size_t	find_newline(char _Nonnull buffer[SIZE]);

// TODO: might want to actually test this lol

/**
 * @brief Gets the next line in a file up to and including '\n'.
 * 
 * @param fd (uint32_t): File descriptor to read from.
 * @return (char *_Nullable): next line in fd, must be freed after use.
*/
char *_Nullable gnl(uint32_t fd) {
	static char 	buffer[SIZE + 1] = "\0";
	static size_t	start = 0;
	static size_t	stop = 0;
	char *_Nonnull	str;

	str = stralloc(0);
	if (str == NULL) {
		return (NULL);
	}

	while (buffer[stop] != '\n') {	
		if (start == 0 || buffer[start] == '\0') {
			save_to_buffer(fd, buffer, &start, &stop);
		}

		if (errno != 0) {
			return (NULL);
		}

		save_to_str(&str, buffer, &start, &stop);
	}

	return (str);
}

static inline uint8_t	save_to_str(
	char *_Nonnull *_Nonnull str,
	char _Nonnull buffer[SIZE],
	size_t *_Nonnull start,
	size_t *_Nonnull stop
) {
	char			tmp_char;
	char *_Nonnull	tmp_str;

	if (str == NULL || *str == NULL || buffer == NULL || start == NULL || stop == NULL) {
		return (EXIT_FAILURE);
	}

	// Marks where to stop the join in case of a '\n'
	tmp_char = '\0';
	if (buffer[*stop] == '\n') {
		tmp_char = buffer[*stop + 1];
		buffer[*stop + 1] = '\0';
	}

	// Attempts to join both strings
	tmp_str = lib_strjoin(*str, buffer + *start);
	free(*str);
	*str = tmp_str;
	if (tmp_str == NULL) {
		errno = ENOMEM;
		return (EXIT_FAILURE);
	}

	// Restores buffer
	if (buffer[*stop] == '\n') {
		buffer[*stop + 1] = tmp_char;
	}

	// Updates boundary indexes, looking for the next '\n'
	*start = *stop + (buffer[*stop] == '\n');
	*stop = find_newline(buffer + *start);

	return (EXIT_SUCCESS);
}

static inline uint8_t	save_to_buffer(
	uint32_t fd,
	char _Nonnull buffer[SIZE],
	size_t *_Nonnull start,
	size_t *_Nonnull stop
) {
	ssize_t	i;

	if (buffer == NULL || start == NULL || stop == NULL) {
		return (EXIT_FAILURE);
	}

	i = read(fd, buffer, SIZE);
	if (i < 0) {
		return (EXIT_FAILURE);
	}
	buffer[i] = '\0';

	// Special trickery for exiting the loop if EOF has been reached
	*start = 0;
	if (i == 0) {
		*stop = 1;
		buffer[1] = '\n';
	} else {
		*stop = find_newline(buffer);
	}

	return (EXIT_SUCCESS);
}

static inline size_t	find_newline(char _Nonnull buffer[SIZE]) {
	size_t	i;

	if (buffer == NULL) {
		return (0);
	}

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n') {
		i++;
	}

	return (i);
}