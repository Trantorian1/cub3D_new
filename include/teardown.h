/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teardown.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:20 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 18:08:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEARDOWN_H
# define TEARDOWN_H

# include <stdint.h>
# include <stdbool.h>
# include "type_annotations.h"
# include "s_programdata.h"

bool	shutdown_trigger(void);
void	shutdown_notify(void);
uint8_t	teardown(const t_programdata *_Nonnull data);

#endif