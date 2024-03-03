/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:36:04 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 13:59:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_ARGS_H
# define VALIDATE_ARGS_H

# include <stdint.h>
# include "type_annotations.h"

uint8_t	validate_args(uint32_t argc, const char *_Nonnull *_Nullable argv);

#endif