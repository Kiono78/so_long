/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:23:56 by bterral           #+#    #+#             */
/*   Updated: 2022/01/10 15:55:32 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mandatory_tiles(t_mlx *mlx)
{
	int	i;
	
	i = 0;
	while (mlx->map[i])
	{
		if (mlx->map[i] == 'P')
			mlx->nb_player++;
		if (mlx->map[i] == 'E')
			mlx->nb_exit++;
		if (mlx->map[i] == 'C')
			mlx->nb_collectible++;
		if (mlx->map[i] != 'C' && mlx->map[i] != 'E' && mlx->map[i] != 'P'
			&& mlx->map[i] != '0' && mlx->map[i] != '1' && mlx->map[i] != '\n')
			mlx->nb_unknown_tile++;
		i++;
	}
	if (mlx->nb_player == 0 || mlx->nb_exit == 0 || mlx->nb_collectible == 0
		|| mlx->nb_unknown_tile > 0 || mlx->x >= 160 || mlx->y >= 90)
	{
		free(mlx->map);
		mlx->map = NULL;
	}
	return (display_error_tiles(&*mlx));
}

char	*add_line_to_map(char *line, t_mlx *mlx)
{
	if (!mlx->map)
		mlx->map = ft_strdup(line);
	else
	{
		mlx->tmp = ft_strjoin(mlx->map, line);
		free(mlx->map);
		mlx->map = mlx->tmp;
	}
	return (mlx->map);
}

int	read_map(int fd, t_mlx *mlx)
{
	char	*current_line;

	initialize_mlx_count(&*mlx);
	current_line = get_next_line(fd);
	if (!current_line)
		return (parsing_error(9));
	mlx->x = ft_line_len(current_line);
	if (is_not_full_walls(current_line))
		return (parsing_error(2));
	while (current_line)
	{
		mlx->map = add_line_to_map(current_line, &*mlx);
		if (ft_line_len(current_line) != mlx->x)
			return (parsing_error(3));
		if (is_not_wall_surrounded(current_line))
			return (parsing_error(4));
		free(current_line);
		current_line = get_next_line(fd);
		mlx->y++;
	}
	if (is_not_full_walls_last_line(mlx->map))
		return (parsing_error(5));
	close(fd);
	return (check_mandatory_tiles(&*mlx));
}

int	open_map(char *file_name, t_mlx *mlx)
{
	int		fd;
	char	*path;

	path = ft_strjoin("maps/", file_name);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
		return (parsing_error(1));
	else
		return (read_map(fd, &*mlx));
}
