/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:41 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/02 11:35:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdio.h>

TestSuite(test_main, .timeout = 1);

Test(test_main, test_main_simple) {
    printf("Build system working\n");

    cr_assert_eq(1, 1);
}