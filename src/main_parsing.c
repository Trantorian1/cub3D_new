/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:27 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/02 16:47:56 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_parsing.h"
#include "libft.h"

// void	my_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;

// 	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
// 	*(int *)pixel = color;
// }

// int	render(t_general *general)
// {
// 	int		i;

// 	if (general->win)
// 	{
// 		i = -1;
// 		while (++i < general->height)
// 		{
// 			my_pixel_put(&general->img, i, 5, 0x06B8EF);
// 		}
// 		mlx_put_image_to_window(general->mlx, general->win, general->img.mlx, 0, 0);
// 	}
// 	return (0);
// }

// int	deal_key(int keysym, t_general *general)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		mlx_destroy_window(general->mlx, general->win);
// 		general->win = NULL;
// 	}
// 	return (0);
// }

// int	close_win(t_general *general)
// {
// 	// free_map(general->map_origin, general->height);
// 	// free_map(general->map_display, general->height);
// 	free(general->mlx);
// 	exit(0);
// 	return (0);
// }

// void	open_window(t_general *general)
// {
// 	general->mlx = mlx_init();
// 	if (!general->mlx)
// 		exit (0);
// 	general->win = mlx_new_window(general->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "hello");
// 	if (!general->win)
// 	{
// 		free(general->win);
// 		exit (0);
// 	}
// 	general->img.mlx = mlx_new_image(general->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	general->img.addr = mlx_get_data_addr(general->img.mlx, &general->img.bpp,
// 			&general->img.line_len, &general->img.endian);
// }


size_t get_file_size(int fd)
{
	size_t size;
	char *line;

	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size += ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	safe_close(fd);
	return (size);
}

int	parse_file(char *file, t_data *data)
{
	data->fd = safe_open(file);
	if (data->fd == -1)
		return (-1);
	
	data->map
}

int	parse_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf(ERROR);
		return (EXIT_FAILURE);		
	}
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	t_data data;
// 	int fd;
// 	size_t file_size;

// 	// (void) argv;
// 	// (void) argc;
	
	if (parse_args(argc, argv) != 0)
		return (EXIT_FAILURE);
	

// 	fd = safe_open(argv[1]);

// 	char *line;
	

// 	file_size = get_file_size(fd);

// 	fd = safe_open(argv[1]);
	
// 	line = get_next_line(fd);
// 	data.file = ft_strjoin("\0", line);

// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		data.file = ft_strjoin_and_free(data.file, line);
// 	}
	
// 	printf("%s\n", data.file);
	
// 	// free(line);

// 	free(data.file);
// 	safe_close(fd);
	


// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_general general;

// 	(void) argc;
// 	(void) argv;

// 	// initiate_general(&general, fd);
// 	general.height = 100;
// 	general.width = 100;
// 	open_window(&general);
// 	mlx_loop_hook(general.mlx, &render, &general);
// 	mlx_hook(general.win, KeyPress, KeyPressMask, &deal_key, &general);
// 	mlx_hook(general.win, 17, 0L, &close_win, &general);
// 	mlx_loop(general.mlx);
// 	mlx_destroy_image(general.mlx, general.img.mlx);
// 	mlx_destroy_display(general.mlx);
// 	free(general.mlx);
// 	return (0);
// }