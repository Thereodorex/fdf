//
// Created by Hugor Chau on 2019-11-29.
//

#ifndef FDF_H
#define FDF_H

/*
**		key_code
*/
#include <zconf.h>

#define KEY_EXIT		53

typedef struct		s_win
{
	void 	*mlx_ptr;
	void	*win_ptr;
}					t_win;

typedef struct 		s_color
{
	int 			z_coord;		//z-ось
	int 			color;
}					t_color;

typedef struct		s_coordinate	//чтобы послать что-то путное в Брезенхайма
{
	int				x;		//x-ось
	int 			y;		//y-ось
	int 			z;		//z-ось
	int 			color;
}					coordinate;


/*
**			алгоритм Брезенхайма
*/

void 		put_line(coordinate first, coordinate second, t_win win);	//сюда отправляю 2 t_coordinate


int 		parse_file(int fd, struct s_color ***all_coord);	//если стороны не равны - это валидно? -1 - неравны, 0 - ок
int			get_max_x(char *map);								//найти x и y для массива
int 		get_all_y(char *map);								//после - замоллочить
int 		get_z(char *map, struct s_color ***all_coord);		//заполнить строку интами (+ цвет?)

#include "../libft/libft.h"
#include "../minilibx/mlx.h"

#endif
