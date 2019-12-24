#include "../incs/fdf.h"
#include <stdio.h>
#include "../../printf/includes/ft_printf.h"

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

//void 		put_line(int x1, int x2, int y1, int y2, int colour, t_win win)
//{
//	int 	deltax;
//	int 	deltay;
//	int 	y_direction;
//	int 	x_direction;
//
//	deltax = x2 - x1 < 0 ? x1 - x2 : x2 - x1;
//	deltay = y2 - y1 < 0 ? y1 - y2 : y2 - y1;
//	y_direction = y2 > y1 ? 1 : -1;
//	x_direction = x2 > x1 ? 1 : -1;
//	get_next_coordinate(0, 0, -1, 0);
//	if (deltay < deltax)
//		while (x1 != x2)
//		{
//			mlx_pixel_put(win.mlx_ptr, win.win_ptr, x1, y1, colour);
//			get_next_coordinate(deltax, y_direction, deltay, &y1);
//			x1 += x_direction;
//		}
//	else
//		while (y1 != y2)
//		{
//			mlx_pixel_put(win.mlx_ptr, win.win_ptr, x1, y1, colour);
//			(get_next_coordinate(deltay, x_direction, deltax, &x1));
//			y1 += y_direction;
//		}
//}

void 		put_line(coordinate first, coordinate second, t_win win)
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
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, first.x, first.y, first.color);
			get_next_coordinate(deltax, y_direction, deltay, &first.y);
			first.x += x_direction;
		}
	else
		while (first.y != second.y)
		{
			mlx_pixel_put(win.mlx_ptr, win.win_ptr, first.x, first.y, first.color);
			(get_next_coordinate(deltay, x_direction, deltax, &first.x));
			first.y += y_direction;
		}
}
