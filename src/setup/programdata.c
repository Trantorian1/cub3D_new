/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:16:00 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/02 16:03:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "programdata.h"

#include <stdlib.h>
#include "mlx.h"
#include "map.h"

uint8_t	mlx(void **result) {
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

uint8_t	programdata(const char *path, t_programdata *result) {
	if (path == NULL || result == NULL) {
		return (EXIT_FAILURE);
	}

	if (map(path, &result->map) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}
	if (mlx(&result->mlx) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}