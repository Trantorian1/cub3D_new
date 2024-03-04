/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:23:09 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 17:34:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PIXEL_H
# define GET_PIXEL_H

# include <stdint.h>
# include "type_annotations.h"
# include "s_programdata.h"

uint32_t *_Nonnull	get_pixel(
    const t_programdata *_Nonnull data,
    uint32_t x,
    uint32_t y
);

#endif // !GET_PIXEL_H