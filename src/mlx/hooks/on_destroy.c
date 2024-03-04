/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:04:27 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 14:14:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "on_destroy.h"

#include <stdlib.h>
#include "teardown.h"

_Noreturn int	on_destroy(const t_programdata *_Nonnull data) {
	exit(teardown(data));
}