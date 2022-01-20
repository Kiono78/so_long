/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:25:58 by bterral           #+#    #+#             */
/*   Updated: 2022/01/20 09:52:57 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_len(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] != '\n')
		count++;
	return (count);
}

void	initialize_mlx_count(t_mlx *mlx)
{
	mlx->nb_player = 0;
	mlx->nb_exit = 0;
	mlx->nb_collectible = 0;
	mlx->nb_unknown_tile = 0;
	mlx->map = NULL;
	mlx->y = 0;
}

int	parsing_error(int error_code)
{
	printf("Error\n");
	if (error_code == 0)
		printf("Map error: Map name is missing !\n");
	if (error_code == 1)
		printf("Map error: Map does not exist !\n");
	if (error_code == 2)
		printf("Map error: First line of the map must be only walls\n");
	if (error_code == 3)
		printf("Map error: Map must be rectangular !\n");
	if (error_code == 4)
		printf("Map error: The map must be fully surrounded by walls\n");
	if (error_code == 5)
		printf("Map error: Last line of the map must be only walls\n");
	if (error_code == 6)
		printf("Map error: A single player must be placed on the map !\n");
	if (error_code == 7)
		printf("Map error: No exit on the map !\n");
	if (error_code == 8)
		printf("Map error: No collectible on the map !\n");
	if (error_code == 9)
		printf("Map error: Map is empty !\n");
	if (error_code == 10)
		printf("Map error: Unknown tile type on the map\n");
	return (0);
}

int	display_error_tiles(t_mlx *mlx)
{
	if (mlx->nb_player != 1)
		return (parsing_error(6));
	else if (mlx->nb_exit == 0)
		return (parsing_error(7));
	else if (mlx->nb_collectible == 0)
		return (parsing_error(8));
	else if (mlx->nb_unknown_tile)
		return (parsing_error(10));
	else if (mlx->x >= 160 || mlx->y >= 90)
	{
		printf("Map error: the map is too big for a 5K screen");
		return (0);
	}
	else
		return (1);
}
