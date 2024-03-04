/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:50:29 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 16:53:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdint.h>
# include "type_annotations.h"
# include "s_programdata.h"

int32_t	renderer(t_programdata *_Nonnull data);

#endif // !RENDERER_H