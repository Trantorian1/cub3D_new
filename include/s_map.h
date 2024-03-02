/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:05:37 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/02 15:48:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

# include <stdint.h>
# include "s_player.h"

# define WALL '1'
# define FLOOR '0'
# define VOID ' '
# define PLAYER 'P'

typedef struct s_map {
	const char		*data;
	const uint32_t	width;
	const uint32_t	height;
	t_player		player;
}	t_map;

#endif