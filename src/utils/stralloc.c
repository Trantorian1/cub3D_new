/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stralloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:01:51 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/10 17:03:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stralloc.h"

#include <stdlib.h>

char *_Nullable	stralloc(size_t n) {
	char *_Nullable	str;

	str = malloc(n + 1);
	if (str == NULL) {
		return (NULL);
	}

	str[n] = '\0';
	return (str);
}