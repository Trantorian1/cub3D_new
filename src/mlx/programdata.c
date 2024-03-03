/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:16:00 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 17:52:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "programdata.h"

#include <stdlib.h>
#include "mlx.h"
#include "map.h"
#include "constants.h"

static uint8_t	mlx(void *_Nonnull *_Nullable result) {
	void	*mlx;

	if (result == NULL) {
		return (EXIT_FAILURE);
	}

	mlx = mlx_init();
	if (mlx == NULL) {
		return (EXIT_FAILURE);
	} else {
		*result = mlx;
	}

	return(EXIT_SUCCESS);
}

static uint8_t	win(void *_Nonnull mlx, void *_Nonnull *_Nullable result) {
	void	*win;

	if (result == NULL) {
		return (EXIT_FAILURE);
	}

	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (mlx == NULL) {
		return (EXIT_FAILURE);
	} else {
		*result = win;
	}

	return (EXIT_SUCCESS);
}

static uint8_t	canvas(void *_Nonnull mlx, void *_Nonnull *_Nullable result) {
	void	*canvas;

	if (result == NULL) {
		return (EXIT_FAILURE);
	}

	canvas = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (canvas == NULL) {
		return (EXIT_FAILURE);
	} else {
		*result = canvas;
	}

	return (EXIT_SUCCESS);
}

uint8_t	programdata(const char *_Nonnull path, t_programdata *_Nonnull result) {
	int32_t	_;

	if (path == NULL || result == NULL) {
		return (EXIT_FAILURE);
	}

	if (map(path, &result->map) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}
	if (mlx(&result->mlx) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}
	if (win(result->mlx, &result->win) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}
	if (canvas(result->mlx, &result->img) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}

	result->canvas = (uint32_t *) mlx_get_data_addr(result->img, &result->Bpp, &result->ls, &_);
	result->Bpp /= 8;

	return (EXIT_SUCCESS);
}