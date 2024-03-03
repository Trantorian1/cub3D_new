/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:01:11 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 14:29:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bind_hooks.h"

#include <stdlib.h>
#include <X11/X.h>
#include "mlx.h"
#include "on_destroy.h"

uint8_t	bind_hooks(t_programdata *_Nonnull data) {
	if (data == NULL) {
		return (EXIT_FAILURE);
	}

	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	return (EXIT_SUCCESS);
}