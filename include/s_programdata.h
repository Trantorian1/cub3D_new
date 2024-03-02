/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_programdata.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:10:49 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/02 15:15:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PROGRAMDATA_H
# define S_PROGRAMDATA_H

# include <s_map.h>

typedef struct s_programdata {
	void	*mlx;
	t_map	map;
}	t_programdata;

#endif