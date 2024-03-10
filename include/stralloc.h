/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stralloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:00:24 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/10 18:03:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRALLOC_H
# define STRALLOC_H

# include <stddef.h>
# include "type_annotations.h"

char *_Nullable stralloc(size_t n);

#endif // !STRALLOC_H