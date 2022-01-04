/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bmlx.y: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:17:23 bmlx.y bterral           #+#    #+#             */
/*   Updated: 2022/01/04 16:54:20 bmlx.y bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	print_kemlx.y(int kemlx.y, void *param)
// {
// 	write(1, 'X', 1);
// 	return (0);
// }

int	parsing_error(int error_code)
{
	printf("Error\n");
	if (error_code == 0)
		printf("Please indicate the map file you want to play on!");
	if (error_code == 1)
		printf("Map requested does not exist, create it under the 'maps' folder");
	return (0);
}

void	init_img(t_mlx *mlx)
{
	int		x;

	x = 0;
	mlx->path[0] = "ground.xpm";
	mlx->path[1] = "wall.xpm";

	while (x < NB_IMAGES)
	{
		mlx->img[x] = mlx_xpm_file_to_image(mlx->ptr, mlx->path[x], &mlx->width[x], &mlx->height[x]);
		x++;
	}
}

char	*open_map(char *file_name)
{
	int	fd;

	fd = open(ft_strjoin("maps/", file_name), O_RDONLY);
	if (fd < 0)
	{
		parsing_error(1);
		return (NULL);
	}
	else
	{
		
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (parsing_error(0));
	mlx.map = open_map(argv[1]);
	if (!mlx.map)
		return (0);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "So long mate !");
	init_img(&mlx);
	mlx.y = 0;
	while (mlx.y < HEIGHT)
	{
		mlx.x = 0;
		while (mlx.x < WIDTH)
		{
			if ((mlx.x % 64) == 0 || (mlx.y % 64) == 0)
				mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img[0], mlx.x, mlx.y);
			else if ((mlx.x % 32) == 0 || (mlx.y % 32) == 0)
				mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img[1], mlx.x, mlx.y);
			mlx.x += 32;
		}
		mlx.y += 32;
	}
	mlx_loop(mlx.ptr);
	return (0);
}