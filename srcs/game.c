/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:33:18 by bterral           #+#    #+#             */
/*   Updated: 2022/01/09 15:22:25 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_manage_action(int keysym, t_mlx *mlx)
{
	if (keysym == K_ESC)
		return (hook_close(&*mlx));
	else
		return (hook_player_move(keysym, &*mlx));
}

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

int	hook_error_message(char character)
{
	if (character == '1')
		printf("Invalid move: Player cannot walk through walls!\n");
	else if (character == 'E')
	{
		printf("Invalid move: Player must collect all its yummy gummy bear ");
		printf("to get the strength to go up that ladder !\n");
	}
	return (0);
}

int	is_valid_pos(char character, t_mlx *mlx)
{
	if (character == '0')
		return (1);
	else if (character == 'C')
		return (1);
	else if (character == 'E' && ft_strchr(mlx->map, 'C') == -1)
		return (1);
	else
		return (hook_error_message(character));
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
		mlx_clear_window(mlx->ptr, mlx->win);
		build_map(&*mlx);
	}
	else
		hook_close(&*mlx);
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