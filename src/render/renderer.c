/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:53:52 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 18:18:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include <stdlib.h>
#include <X11/keysym.h>
#include "mlx.h"
#include "on_key.h"
#include "render_rectangle.h"
#include "constants.h"
#include "teardown.h"

int32_t	renderer(t_programdata *_Nonnull data) {
	if (data == NULL || shutdown_trigger()) {
		return (EXIT_FAILURE);
	}

	if (is_pressed(XK_a)) {
		render_rectangle(data, 0, 0, WIN_WIDTH, WIN_HEIGHT, 0x3D3D3D);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_string_put(data->mlx, data->win, 100, 100, 0xffffff, "Pressed key: A");
	} else if(is_pressed(XK_Escape)) {
		shutdown_notify();
		mlx_loop_end(data->mlx);
	} else {
		render_rectangle(data, 0, 0, WIN_WIDTH, WIN_HEIGHT, 0x0);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}

	return (EXIT_SUCCESS);
}