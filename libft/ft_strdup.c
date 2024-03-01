/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:20:14 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/02/29 14:17:27 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*str;
	char		*s_bis;

	i = 0;
	s_bis = (char *)s;
	while (s_bis[i] && s_bis[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i) + 1);
	if (!str || !s)
		return (NULL);
	while (s_bis[i])
	{
		str[i] = s_bis[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	char string[] = "Yooooooooooooo";
	char src1[100] = "AuRevoir";
	printf("%s\n", ft_strdup(string));
	return (0);
}
*/