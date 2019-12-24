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
#include "mlx.h"

#define ESCAPE			53
#define KEY_EXIT		53

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		current_x;
	int		current_y;
	int		mouse_pressed;
}				t_param;

typedef struct		s_coord
{
	int				x;
	int 			y;
	int				z;
	int 			color;
}					t_coord;

typedef struct		s_node
{
	t_coord					prime;
	t_coord					current;
	struct s_node		*right;
	struct s_node		*down;
}									t_node;

void 		put_line(t_coord first, t_coord second, t_param *param);
t_node		*parse_file(char *filename);

#endif