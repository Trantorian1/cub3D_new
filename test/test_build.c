/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:41 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/02 17:33:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdio.h>

TestSuite(test_build, .timeout = 1);

Test(test_build, test_build_simple) {
    printf("Build system working\n");

    cr_assert_eq(1, 1);
}