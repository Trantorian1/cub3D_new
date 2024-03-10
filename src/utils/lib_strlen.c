/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:09:26 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/10 17:10:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_strlen.h"

size_t  lib_strlen(char *_Nonnull str) {
	size_t	len;

	if (str == NULL) {
		return (0);
	}

	len = 0;
	while (str[len] != '\0') {
		len++;
	}

	return (len);
}