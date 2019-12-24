#include "header.h"
#include <stdio.h>

/*
**			алгоритм Брезенхайма
*/

static int 		get_next_coordinate(int delta, int dirx, int distortion, int *x1)
{
	static int 	error = 0;

	if (distortion == -1)
	{
		error = 0;
		return (0);
	}
	error += distortion;
	if (error * 2 >= delta)
	{
		*x1 = *x1 + dirx;
		error = error - delta;
	}
	return (1);
}

void 		put_line(t_coord first, t_coord second, t_param *param)
{
	int 	deltax;
	int 	deltay;
	int 	y_direction;
	int 	x_direction;

	deltax = second.x - first.x < 0 ? first.x - second.x : second.x - first.x;
	deltay = second.y - first.y < 0 ? first.y - second.y : second.y - first.y;
	y_direction = second.y > first.y ? 1 : -1;
	x_direction = second.x > first.x ? 1 : -1;
	get_next_coordinate(0, 0, -1, 0);
	if (deltay < deltax)
		while (first.x != second.x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, first.x, first.y, first.color);
			get_next_coordinate(deltax, y_direction, deltay, &first.y);
			first.x += x_direction;
		}
	else
		while (first.y != second.y)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, first.x, first.y, first.color);
			(get_next_coordinate(deltay, x_direction, deltax, &first.x));
			first.y += y_direction;
		}
}
