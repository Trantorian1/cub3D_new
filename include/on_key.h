/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:38:18 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 15:44:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ON_KEY_H
# define ON_KEY_H

# include <stdint.h>
# include <stdbool.h>
# include "type_annotations.h"
# include "s_programdata.h"

uint64_t *_Nonnull	keymap(void);
uint8_t				keypos(uint32_t keysym);
int					on_keypress(int32_t keysym, const void *_Nullable _);
int					on_keyrelease(int32_t keysym, const void *_Nonnull _);
bool				is_pressed(int32_t keysym);

#endif // !ON_KEY_H