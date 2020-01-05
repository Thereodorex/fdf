/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:02:31 by jcorwin           #+#    #+#             */
/*   Updated: 2019/12/08 16:02:35 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"

#define INDENT			15
#define SIZE_WINDOW		1000
#define ESCAPE			53
#define KEY_EXIT		53

typedef struct		s_coord
{
	int				x;
	int 			y;
	int				z;
	int 			color;
}					t_coord;

typedef struct		s_node
{
	t_coord				prime;
	t_coord				current;
	struct s_node		*right;
	struct s_node		*down;
}									t_node;

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_node	*map;
	double	x_rot;
	double	y_rot;
	double	z_rot;
	int		x_move;
	int		y_move;
	int		base_color;
	// int		current_x;
	// int		current_y;
	// int		mouse_pressed;
}				t_param;

void 		put_line(t_coord first, t_coord second, t_param *param);
t_node		*parse_file(char *filename);
void		figure_scale(t_node *node);

void	print_map(t_param *param);
int close_fdf(void *param);
int key_press(int keycode, t_param *param);
int mouse_move(int x, int y, t_param *param);
int mouse_press(int button, int x, int y, t_param *param);
int mouse_release(int button, int x, int y, t_param *param);
char	*record_color(char *ptr, int *color);
void	rotate_map(t_param *param);

#endif