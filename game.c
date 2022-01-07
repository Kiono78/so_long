/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:33:18 by bterral           #+#    #+#             */
/*   Updated: 2022/01/07 17:19:39 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int hook_manage_action(int keysym, t_mlx *mlx)
{
	if (keysym == K_ESC)
		return (hook_close(keysym, &*mlx));
	else
		return (hook_player_move(keysym, &*mlx));
}

int	key_hook_print(int keysym, t_mlx *mlx)
{
	printf("key id: %d", keysym);
	return (0);
}

int hook_close(int keysym, t_mlx *mlx)
{
	int img_count;

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

int is_valid_pos(char character)
{
	if (character == '0')
		return (1);
	else if (character == '1')
		return (0);
	else if (character == 'C')
		return (1);
	//must be improved by counting number of collectible
	else if (character == 'E')
		return (1);
	else
		return (0);
}

int	hook_player_move(int keysym, t_mlx *mlx)
{
	int			pos;
	static int	count;

	pos = ft_strchr(mlx->map, 'P');
	if (keysym == K_W || keysym == K_UP)
	{
		if (is_valid_pos(mlx->map[pos - mlx->x - 1]))
		{
			mlx->map[pos - mlx->x - 1] = 'P';
			mlx->map[pos] = '0';
			count++;
			printf("test");
			mlx_clear_window(mlx->ptr, mlx->win);
			build_map(&*mlx);
		}
	}
	else if (keysym == K_S || keysym == K_DOWN)
	{
		if (is_valid_pos(mlx->map[pos + mlx->x + 1]))
		{
			mlx->map[pos + mlx->x + 1] = 'P';
			mlx->map[pos] = '0';
			count++;
			mlx_clear_window(mlx->ptr, mlx->win);
			build_map(&*mlx);
		}
	}
	else if (keysym == K_A || keysym == K_LEFT)
	{
		if (is_valid_pos(mlx->map[pos - 1]))
		{
			mlx->map[pos - 1] = 'P';
			mlx->map[pos] = '0';
			count++;
			mlx_clear_window(mlx->ptr, mlx->win);
			build_map(&*mlx);
		}
	}
	else if (keysym == K_D || keysym == K_RIGHT)
	{
		if (is_valid_pos(mlx->map[pos + 1]))
		{
			mlx->map[pos + 1] = 'P';
			mlx->map[pos] = '0';
			count++;
			mlx_clear_window(mlx->ptr, mlx->win);
			build_map(&*mlx);
		}
	}
	printf("move : %d", count);
	return (0);
}