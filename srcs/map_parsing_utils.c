/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:25:58 by bterral           #+#    #+#             */
/*   Updated: 2022/01/09 15:29:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_full_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_not_full_walls_last_line(char *map)
{
	int	length;

	length = ft_strlen(map);
	length--;
	while (map[length] && map[length] != '\n')
	{
		if (map[length] != '1')
			return (1);
		length--;
	}
	return (0);
}

int	is_not_wall_surrounded(char *line)
{
	if (*line != '1')
		return (1);
	line++;
	while (*(line + 1) != '\n' && *(line + 1))
		line++;
	if (*line != '1')
		return (1);
	return (0);
}

size_t	ft_line_len(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] != '\n')
		count++;
	return (count);
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
	return (0);
}
