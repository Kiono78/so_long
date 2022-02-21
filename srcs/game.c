/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:33:18 by bterral           #+#    #+#             */
/*   Updated: 2022/02/04 10:33:21 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_close(t_mlx *mlx)
{
	int	img_count;

	img_count = 0;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	while (img_count < 5)
	{
		mlx_destroy_image(mlx->ptr, mlx->img[img_count]);
		img_count++;
	}
	exit(mlx->loop);
	return (0);
}

int	hook_change_map(t_mlx *mlx, int new_pos, int old_pos)
{
	static int	count;

	count++;
	printf("nb move : %d\n", count);
	if (mlx->map[new_pos] != 'E')
	{
		mlx->map[new_pos] = 'P';
		mlx->map[old_pos] = '0';
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[3],
			(new_pos % (mlx->x + 1)) * 32, (new_pos / (mlx->x + 1) * 32));
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img[0],
			(old_pos % (mlx->x + 1)) * 32, (old_pos / (mlx->x + 1) * 32));
	}
	else
	{
		printf("You won in %d moves ! GG WP !\n", count);
		hook_close(&*mlx);
	}
	return (1);
}

int	hook_player_move(int keysym, t_mlx *mlx)
{
	int			pos;

	pos = ft_strchr(mlx->map, 'P');
	if ((keysym == K_W || keysym == K_UP)
		&& is_valid_pos(mlx->map[pos - mlx->x - 1], &*mlx))
		return (hook_change_map(&*mlx, pos - mlx->x - 1, pos));
	else if ((keysym == K_S || keysym == K_DOWN)
		&& is_valid_pos(mlx->map[pos + mlx->x + 1], &*mlx))
		return (hook_change_map(&*mlx, pos + mlx->x + 1, pos));
	else if ((keysym == K_A || keysym == K_LEFT)
		&& is_valid_pos(mlx->map[pos - 1], &*mlx))
		return (hook_change_map(&*mlx, pos - 1, pos));
	else if ((keysym == K_D || keysym == K_RIGHT)
		&& is_valid_pos(mlx->map[pos + 1], &*mlx))
		return (hook_change_map(&*mlx, pos + 1, pos));
	return (0);
}
