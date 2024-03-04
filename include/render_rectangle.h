/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangle.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:38:42 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 17:41:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_RECTANGLE_H
# define RENDER_RECTANGLE_H

# include <stdint.h>
# include "type_annotations.h"
# include "s_programdata.h"

uint8_t render_rectangle(
    t_programdata *_Nonnull data,
    uint32_t x,
    uint32_t y,
    uint32_t width,
    uint32_t height,
    uint32_t color
);

#endif // !RENDER_RECTANGLE_H