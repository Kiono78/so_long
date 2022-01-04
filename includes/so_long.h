/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:52:38 by bterral           #+#    #+#             */
/*   Updated: 2022/01/04 17:08:10 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "keys.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define HEIGHT 960
# define WIDTH 1600
# define NB_IMAGES 2

typedef struct s_mlx
{
	char	*map;
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	char	*path[NB_IMAGES];
	void	*img[NB_IMAGES];
	int		width[NB_IMAGES];
	int		height[NB_IMAGES];
}	t_mlx;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

#endif