/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:52:38 by bterral           #+#    #+#             */
/*   Updated: 2022/01/10 15:38:28 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "keys.h"
# include "../get_next_line/includes/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define NB_IMAGES 5

typedef struct s_mlx
{
	int		loop;
	char	*map;
	char	*tmp;
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	char	*path[NB_IMAGES];
	void	*img[NB_IMAGES];
	int		width[NB_IMAGES];
	int		height[NB_IMAGES];
	int		nb_player;
	int		nb_collectible;
	int		nb_exit;
	int		nb_unknown_tile;
}	t_mlx;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;


////////////////////////////////////////
//            Main                    //
////////////////////////////////////////

void	init_img(t_mlx *mlx);
void	build_map(t_mlx *mlx);

////////////////////////////////////////
//            Map parsing             //
////////////////////////////////////////

int		is_not_full_walls(char *line);
int 	is_not_full_walls_last_line(char *map);
int 	is_not_wall_surrounded(char *line);
int		ft_line_len(const char *str);
int		parsing_error(int error_code);
int 	check_mandatory_tiles(t_mlx *mlx);
int		display_error_tiles(t_mlx *mlx);
char	*add_line_to_map(char *line, t_mlx *mlx);
int 	read_map(int fd, t_mlx *mlx);
int		open_map(char *file_name, t_mlx *mlx);
void 	initialize_mlx_count(t_mlx *mlx);

////////////////////////////////////////
//            Hook                    //
////////////////////////////////////////

int 	hook_manage_action(int keysym, t_mlx *mlx);
int		key_hook_print(int keysym, t_mlx *mlx);
int 	hook_close(t_mlx *mlx);
int 	is_valid_pos(char character, t_mlx *mlx);
int		hook_player_move(int keysym, t_mlx *mlx);
int		hook_change_map(t_mlx *mlx, int new_pos, int old_pos);

#endif