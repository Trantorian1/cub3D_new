/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:36:29 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 14:16:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "validate_args.h"

uint8_t	validate_args(uint32_t argc, const char *argv[]) {
	if (argc != 2 || argv[1] == NULL) {
		errno = EINVAL;
		perror("❌ Invalid args");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}