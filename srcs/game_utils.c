/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:32:58 by bterral           #+#    #+#             */
/*   Updated: 2022/02/04 10:35:28 by bterral          ###   ########.fr       */
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
