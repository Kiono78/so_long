/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:17:23 by x.y bterral       #+#    #+#             */
/*   Updated: 2022/01/05 18:32:52 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_img(t_mlx *mlx)
{
	int		x;

	x = 0;
	mlx->path[0] = "ground.xpm";
	mlx->path[1] = "wall.xpm";

	while (x < NB_IMAGES)
	{
		mlx->img[x] = mlx_xpm_file_to_image(mlx->ptr, mlx->path[x], &mlx->width[x], &mlx->height[x]);
		x++;
	}
}

int	is_not_full_walls(char *line)
{
	while (*line != '\n' && *line)
	{
		if (*line != '1')
			return (1);
		line++;
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

int check_mandatory_tiles(t_mlx *mlx)
{
	mlx->nb_player = 0;
	mlx->nb_exit = 0;
	mlx->nb_collectible = 0;
	while (*mlx->map)
	{
		if (*mlx->map == 'P')
			mlx->nb_player++;
		if (*mlx->map == 'E')
			mlx->nb_exit++;
		if (*mlx->map == 'C')
			mlx->nb_collectible++;
		mlx->map++;
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

int read_map(int fd, t_mlx *mlx)
{
	char	*previous_line;
	char	*current_line;
	size_t	length;

//add a function to clean before sending error
	mlx->map = NULL;
	current_line = get_next_line(fd);
	length = ft_line_len(current_line);
	if (is_not_full_walls(current_line))
		return (parsing_error(2));
	while (current_line)
	{
		mlx->map = add_line_to_map(current_line, &*mlx);
		if (ft_line_len(current_line) != length)
			return (parsing_error(3));
		if (is_not_wall_surrounded(current_line))
			return (parsing_error(4));
		ft_strcpy(previous_line, current_line);
		current_line = get_next_line(fd);
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

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (parsing_error(0));
	if (open_map(argv[1], &mlx) == 0)
		return (0);
	// mlx.ptr = mlx_init();
	// mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "So long mate !");
	// init_img(&mlx);
	// mlx.y = 0;
	// while (mlx.y < HEIGHT)
	// {
	// 	mlx.x = 0;
	// 	while (mlx.x < WIDTH)
	// 	{
	// 		if ((mlx.x % 64) == 0 || (mlx.y % 64) == 0)
	// 			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img[0], mlx.x, mlx.y);
	// 		else if ((mlx.x % 32) == 0 || (mlx.y % 32) == 0)
	// 			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img[1], mlx.x, mlx.y);
	// 		mlx.x += 32;
	// 	}
	// 	mlx.y += 32;
	// }
	// mlx_loop(mlx.ptr);
	return (0);
}