#include "header.h"
#include <stdio.h>
#include <math.h>

/*
**			алгоритм Брезенхайма
*/

static int 		get_next_coordinate(int delta, int dirx, int distortion, int *x1)
{
	static int 	error = 0;

	error += distortion;
	if (error * 2 >= delta)
	{
		*x1 = *x1 + dirx;
		error = error - delta;
	}
	return (1);
}

double percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			find_gradient(t_coord current, t_coord start, t_coord end, t_coord delta)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void 		put_line(t_coord first, t_coord second, t_param *param)
{
	t_coord		delta;
	t_coord		direction;
	t_coord		new;

	new = first;
	delta.x = second.x - first.x < 0 ? first.x - second.x : second.x - first.x;
	delta.y = second.y - first.y < 0 ? first.y - second.y : second.y - first.y;
	direction.y = second.y > first.y ? 1 : -1;
	direction.x = second.x > first.x ? 1 : -1;
	if (delta.y < delta.x)
		while (new.x != second.x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, new.x, new.y, new.color);
			get_next_coordinate(delta.x, direction.y, delta.y, &new.y);
			new.x += direction.x;
			new.color = find_gradient(new, first, second, delta);
		}
	else
		while (new.y != second.y)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, new.x, new.y, new.color);
			get_next_coordinate(delta.y, direction.x, delta.x, &new.x);
			new.y += direction.y;
			new.color = find_gradient(new, first, second, delta);
		}
}
