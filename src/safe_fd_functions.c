/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_fd_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:15 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/02/29 14:05:58 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_parsing.h"

int safe_open(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf(OPEN_FD_ERROR);	
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	safe_close(int fd)
{
	if (close(fd) == -1)
	{
		printf(CLOSE_FD_ERROR);
		exit(EXIT_FAILURE);
	}
	return ;
}