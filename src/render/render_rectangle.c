/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:40:04 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 17:51:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_rectangle.h"

#include <stdlib.h>
#include "get_pixel.h"

uint8_t render_rectangle(
    t_programdata *_Nonnull data,
    uint32_t x,
    uint32_t y,
    uint32_t width,
    uint32_t height,
    uint32_t color
) {
	uint32_t *_Nonnull	pixel;
	uint32_t *_Nonnull	target;

	if (data == NULL || width > UINT32_MAX / height) {
		return (EXIT_FAILURE);
	}

	pixel = get_pixel(data, x, y);
	target = pixel + width * height;

	while (pixel < target) {
		*pixel = color;
		pixel++;
	}

	return (EXIT_SUCCESS);
}