/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_on_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:25:12 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 15:51:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/parameterized.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "on_key.h"

typedef struct s_param {
	uint32_t	keysym;
	uint32_t	pos;
}	t_param;

static const t_param g_params[] = {
	{ XK_a, 0 },
	{ XK_b, 2 },
	{ XK_c, 3 },
	{ XK_d, 4 },
	{ XK_e, 5 },
	{ XK_f, 6 },
	{ XK_g, 7 },
	{ XK_h, 8 },
	{ XK_i, 9 },
	{ XK_j, 10 },
	{ XK_k, 11 },
	{ XK_l, 12 },
	{ XK_m, 13 },
	{ XK_n, 14 },
	{ XK_o, 15 },
	{ XK_p, 16 },
	{ XK_q, 17 },
	{ XK_r, 18 },
	{ XK_s, 19 },
	{ XK_t, 20 },
	{ XK_u, 21 },
	{ XK_v, 22 },
	{ XK_x, 23 },
	{ XK_y, 24 },
	{ XK_z, 25 },
	{ XK_0, 26 },
	{ XK_1, 27 },
	{ XK_2, 28 },
	{ XK_3, 29 },
	{ XK_4, 30 },
	{ XK_5, 31 },
	{ XK_6, 32 },
	{ XK_7, 33 },
	{ XK_8, 34 },
	{ XK_9, 35 },
	{ XK_Left, 36 },
	{ XK_Up, 37 },
	{ XK_Right, 38 },
	{ XK_Down, 39 },
	{ XK_Control_L, 40 },
	{ XK_Shift_L, 41 },
	{ XK_Escape, 42 },
};

void setup(void) {
	*keymap() = 0;
}

TestSuite(on_key, .timeout = 1);

ParameterizedTestParameters(on_key, on_key_test) {
	size_t	nb_params;

	nb_params = sizeof(g_params) / sizeof(*g_params);
	return (cr_make_param_array(t_param, g_params, nb_params));
}

ParameterizedTest(t_param *param, on_key, on_key_test, .init = setup) {
	on_keypress(param->keysym, NULL);
	printf("💡 Just pressed key at pos %d\n", keypos(param->keysym));
	printf(" > keymap: %ld\n", *keymap());

	cr_assert_eq(is_pressed(param->keysym), true);
	on_keyrelease(param->keysym, NULL);
	cr_assert_eq(is_pressed(param->keysym), false);
	cr_assert_eq(*keymap(), 0);
}