/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teardown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:47 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 14:22:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "teardown.h"

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

uint8_t	teardown(const t_programdata *data) {
	if (data == NULL) {
		return (EXIT_FAILURE);
	}

	if (data->win != NULL) {
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx != NULL) {
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}

	return (EXIT_SUCCESS);
}