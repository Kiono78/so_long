/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:23:56 by bterral           #+#    #+#             */
/*   Updated: 2022/01/06 14:39:29 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_mandatory_tiles(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->nb_player = 0;
	mlx->nb_exit = 0;
	mlx->nb_collectible = 0;
	while (mlx->map[i])
	{
		if (mlx->map[i] == 'P')
			mlx->nb_player++;
		if (mlx->map[i] == 'E')
			mlx->nb_exit++;
		if (mlx->map[i] == 'C')
			mlx->nb_collectible++;
		i++;
	}
	if (mlx->nb_player == 0 || mlx->nb_exit == 0 || mlx->nb_collectible == 0)
	{
		// free(mlx->map);
		mlx->map = NULL;
	}
	if (mlx->nb_player == 0)
		return (parsing_error(6));
	else if (mlx->nb_exit == 0)
		return (parsing_error(7));
	else if (mlx->nb_collectible == 0)
		return (parsing_error(8));
	else
		return (1);
}

char	*add_line_to_map(char *line, t_mlx *mlx)
{
	if (!mlx->map)
		return (ft_strdup(line));
	else
	{
		mlx->tmp = ft_strjoin(mlx->map, line);
		free(mlx->map);
		mlx->map = mlx->tmp;
		return (mlx->map);
	}
}

int read_map(int fd, t_mlx *mlx)
{
	char	*previous_line;
	char	*current_line;

//add a function to clean before sending error
	mlx->map = NULL;
	mlx->y = 0;
	current_line = get_next_line(fd);
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
		ft_strcpy(previous_line, current_line);
		free(current_line);
		current_line = get_next_line(fd);
		mlx->y++;
	}
	if (is_not_full_walls(previous_line))
		return (parsing_error(5));
	return (check_mandatory_tiles(&*mlx));
}

int	open_map(char *file_name, t_mlx *mlx)
{
	int		fd;

	fd = open(ft_strjoin("maps/", file_name), O_RDONLY);
	if (fd < 0)
		return (parsing_error(1));
	else
		return (read_map(fd, &*mlx));
}