/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:02:42 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 14:14:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ON_DESTROY_H
# define ON_DESTROY_H

# include "type_annotations.h"
# include "s_programdata.h"

_Noreturn int on_destroy(const t_programdata *_Nonnull data);

#endif