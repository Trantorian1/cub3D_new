/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_programdata.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:10:49 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 13:58:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PROGRAMDATA_H
# define S_PROGRAMDATA_H

# include <s_map.h>
# include "type_annotations.h"

typedef struct s_programdata {
	t_map			map;
	void *_Nonnull	mlx;
	void *_Nonnull	win;
}	t_programdata;

#endif