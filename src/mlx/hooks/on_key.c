/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:43:00 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 15:51:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "on_key.h"

#include <X11/keysym.h>
#include <stdlib.h>

/**
 * 64-bit buffer where each bit corresponds to a different key
 * 
 * [ABCDEGFGHIJKLMNOPQRSTUVWXYZ][0123456789][Left-Up-Right-Down][Ctrl-Shift-Esc]
*/
uint64_t *_Nonnull keymap(void) {
	static uint64_t	map = 0;

	return (&map);
}

/**
 * @brief Converts an X11 key symbol to a position in the keymap buffer.
 * 
 * @param keysym (uint32_t) X11 key symbol.
 * @returns (uint8_t) The position of [keysym] in the keymap buffer.
*/
uint8_t	keypos(uint32_t keysym) {
	if (keysym >= XK_a && keysym <= XK_z) {
		return (keysym - XK_a);
	} else if (keysym >= XK_0 && keysym <= XK_9) {
		return (keysym - XK_0 + 26);
	} else if (keysym >= XK_Left && keysym <= XK_Down) {
		return (keysym - XK_Left + 36);
	} else if (keysym == XK_Control_L) {
		return (40);
	} else if (keysym == XK_Shift_L) {
		return (41);
	} else if (keysym == XK_Escape) {
		return (42);
	} else {
		return (65);
	}
}

int		on_keypress(int32_t keysym, const void *_Nullable _) {
	const uint8_t	pos = keypos(keysym);
	const uint64_t	mask = 1 << pos;

	(void)_;
	if (pos < 65) {
		*keymap() |= mask;
	}

	return (EXIT_SUCCESS);
}

int		on_keyrelease(int32_t keysym, const void *_Nonnull _) {
	const uint8_t	pos = keypos(keysym);
	const uint64_t	mask = ~(1 << pos);

	(void)_;
	if (pos < 65) {
		*keymap() &= mask;
	}

	return (EXIT_SUCCESS);
}

bool	is_pressed(int32_t keysym) {
	const uint8_t	pos = keypos(keysym);
	const uint64_t	mask = 1 << pos;

	if (pos == 65) {
		return (false);
	} else {
		return (*keymap() & mask);
	}
}