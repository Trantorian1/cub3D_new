/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strlen.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:08:36 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/10 17:09:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STRLEN_H
# define LIB_STRLEN_H

# include <stddef.h>
# include "type_annotations.h"

size_t  lib_strlen(char *_Nonnull str);

#endif // !LIB_STRLEN_H