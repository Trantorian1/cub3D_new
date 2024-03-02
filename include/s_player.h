/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:06:21 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/02 15:08:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PLAYER_H
# define S_PLAYER_H

# include <stdint.h>

typedef struct s_player {
	uint32_t	x;
	uint32_t	y;
}	t_player;

#endif