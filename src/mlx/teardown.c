/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teardown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:47 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 18:08:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "teardown.h"

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

static bool g_trigger = false;

bool	shutdown_trigger(void) {
	return (g_trigger);
}

void	shutdown_notify(void) {
	g_trigger = true;
}

uint8_t	teardown(const t_programdata *data) {
	if (data == NULL || data->mlx == NULL) {
		return (EXIT_FAILURE);
	}

	shutdown_notify();

	if (data->win != NULL) {
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->img != NULL) {
		mlx_destroy_image(data->mlx, data->img);
	}

	mlx_destroy_display(data->mlx);
	free(data->mlx);

	return (EXIT_SUCCESS);
}