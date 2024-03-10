/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:07:22 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/10 17:14:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib_strjoin.h"

#include <stdlib.h>
#include <stddef.h>
#include "lib_strlen.h"
#include "stralloc.h"

uint8_t lib_strjoin(char *_Nonnull str_a, char *_Nonnull str_b) {
	size_t			len_a;
	size_t			len_b;
	char *_Nonnull	str_join;
	char *_Nonnull	cursor;

	if (str_a == NULL || str_b == NULL) {
		return (EXIT_FAILURE);
	}

	len_a = lib_strlen(str_a);
	len_b = lib_strlen(str_b);
	str_join = stralloc(len_a + len_b);

	cursor = str_join;
	while (*str_a) {
		*cursor++ = *str_a++;
	}

	while (*str_b) {
		*cursor++ = *str_b++;
	}

	return (str_join);
}