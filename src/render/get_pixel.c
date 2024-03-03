/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:33:32 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 17:48:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_pixel.h"

#include <stdlib.h>

uint32_t *_Nonnull	get_pixel(
	const t_programdata *_Nonnull data,
	uint32_t x,
	uint32_t y
) {
	static uint32_t dummy = 0x0;

	if (data == NULL) {
		return (&dummy);
	}

	return (data->canvas + y * data->ls + x * data->Bpp);
}