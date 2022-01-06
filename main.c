/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:17:23 by x.y bterral       #+#    #+#             */
/*   Updated: 2022/01/06 13:38:27 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_mlx *mlx)
{
	int		x;

	x = 0;
	mlx->path[0] = "xpm/ground.xpm";
	mlx->path[1] = "xpm/wall.xpm";
	mlx->path[2] = "xpm/collectible.xpm";
	mlx->path[3] = "xpm/player.xpm";
	mlx->path[4] = "xpm/exit.xpm";
	while (x < NB_IMAGES)
	{
		mlx->img[x] = mlx_xpm_file_to_image(mlx->ptr, mlx->path[x], &mlx->width[x], &mlx->height[x]);
		x++;
	}
}

void	build_map(t_mlx *mlx)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (mlx->map[i])
	{
		if (mlx->map[i] == '0')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[0], x, y);
		else if (mlx->map[i] == '1')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[1], x, y);
		else if (mlx->map[i] == 'C')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[2], x, y);
		else if (mlx->map[i] == 'P')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[3], x, y);
		else if (mlx->map[i] == 'E')
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[4], x, y);
		if (mlx->map[i] == '\n')
		{
			x = 0;
			y += 32;
		}
		else
			x += 32;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (parsing_error(0));
	if (open_map(argv[1], &mlx) == 0)
		return (0);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, mlx.x * 32, mlx.y * 32, "So long mate !");
	init_img(&mlx);
	build_map(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}




// while (mlx.y < mlx.y * 32)
	// {
	// 	mlx.x = 0;
	// 	while (mlx.x < mlx.x * 32)
	// 	{
	// 		if ((mlx.x % 64) == 0 || (mlx.y % 64) == 0)
	// 			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img[0], mlx.x, mlx.y);
	// 		else if ((mlx.x % 32) == 0 || (mlx.y % 32) == 0)
	// 			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img[1], mlx.x, mlx.y);
	// 		mlx.x += 32;
	// 	}
	// 	mlx.y += 32;
	// }