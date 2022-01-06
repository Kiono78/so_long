/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:25:58 by bterral           #+#    #+#             */
/*   Updated: 2022/01/06 14:31:29 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_full_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int is_not_wall_surrounded(char *line)
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
		printf("Please indicate the map file you want to play on!\n");
	if (error_code == 1)
		printf("Map requested does not exist, create it under the 'maps' folder\n");
	if (error_code == 2)
		printf("First line of the map must be only walls\n");
	if (error_code == 3)
		printf("Map must be rectangular !\n");
	if (error_code == 4)
		printf("The map must be fully surrounded by walls on both sides\n");
	if (error_code == 5)
		printf("Last line of the map must be only walls\n");
	if (error_code == 6)
		printf("No player on the map !\n");
	if (error_code == 7)
		printf("No exit on the map !\n");
	if (error_code == 8)
		printf("No collectible on the map !\n");
	return (0);
}