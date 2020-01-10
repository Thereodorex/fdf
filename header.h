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

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "keycode_fdf.h"

/*
**		map size
*/
# define INDENT			15
# define SIZE_WINDOW	1300

/*
**		error management
*/
# define NO_ARG			1
# define ERROR_MAP		2
# define MISSING_MAP	3
# define NOT_A_MAP		4

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_node
{
	t_coord			prime;
	t_coord			current;
	struct s_node	*right;
	struct s_node	*down;
}					t_node;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_node			*map;
	double			x_rot;
	double			y_rot;
	double			z_rot;
	int				x_move;
	int				y_move;
	int				base_color;
	int				high_base_color;
	t_coord			scale;
	t_coord			indent;
	int				max_size;
	t_image			*image;
	// int		current_x;
	// int		current_y;
	// int		mouse_pressed;
}					t_param;

void				put_line(t_coord first, t_coord second, t_param *prm);
t_node				*parse_file(char *filename);
void				figure_scale(t_node *node, t_coord *indent, t_coord *scale);
void				print_map(t_param *param);
int					close_fdf(void *param);
int					key_press(int keycode, t_param *param);
int					mouse_move(int x, int y, t_param *param);
int					mouse_press(int button, int x, int y, t_param *param);
int					mouse_release(int button, int x, int y, t_param *param);
char				*record_color(char *ptr, int *color);
void				rotate_map(t_param *param);
char				*read_file(int fd);
int					find_gradient(t_coord current, t_coord start,
												t_coord end, t_coord delta);
int					count_scale_z(t_node *node, int max_size);
int					count_scale_x(t_node *node);
int					count_scale_y(t_node *node);
void				image_set_pixel(t_image **image, int x, int y, int color);
void				clear_image(t_image *image);
void				create_img(t_param *param);
/*
**		key events
*/
int					key_exit(int keycode, t_param *param);
int					key_size(int keycode, t_param *param);
int					key_rot(int keycode, t_param *param);
int					key_move(int keycode, t_param *param);
int					key_color(int keycode, t_param *param);
int					key_default(int keycode, t_param *param);
int					mouse_scroll(int button, int x, int y, t_param *param);
/*
**		error manangement
*/
void				fdf_error(int code);
void				clear_node(t_node **arr);
int					close_fdf(void *param);
/*
**		from libft
*/
void				ft_bzero(void *s, size_t n);

#endif
