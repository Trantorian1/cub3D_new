/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:05:37 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 13:58:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

# include <stdint.h>
# include "type_annotations.h"
# include "s_player.h"

# define WALL '1'
# define FLOOR '0'
# define VOID ' '
# define PLAYER 'P'
# define R 0xff0000
# define G 0x00ff00
# define B 0x0000ff

typedef struct s_map {
	const char *_Nonnull	data;
	const uint32_t			width;
	const uint32_t			height;
	const uint32_t			color_sky;
	const uint32_t			color_floor;
	t_player				player;
}	t_map;

#endif