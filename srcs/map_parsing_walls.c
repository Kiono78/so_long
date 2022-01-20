/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:35:08 by bterral           #+#    #+#             */
/*   Updated: 2022/01/20 09:53:04 by bterral          ###   ########.fr       */
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
