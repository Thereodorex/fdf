/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:15:31 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:15:33 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <math.h>

/*
**			алгоритм Брезенхайма
*/

static int		get_next_coordinate(int delta, int dirx,
											int distortion, int *x1)
{
	static int	error = 0;

	error += distortion;
	if (error * 2 >= delta)
	{
		*x1 = *x1 + dirx;
		error = error - delta;
	}
	return (1);
}

void			put_line(t_coord frst, t_coord sec, t_param *prm)
{
	t_coord		delta;
	t_coord		direction;
	t_coord		new;

	new = frst;
	delta.x = sec.x - frst.x < 0 ? frst.x - sec.x : sec.x - frst.x;
	delta.y = sec.y - frst.y < 0 ? frst.y - sec.y : sec.y - frst.y;
	direction.y = sec.y > frst.y ? 1 : -1;
	direction.x = sec.x > frst.x ? 1 : -1;
	if (delta.y < delta.x)
		while (new.x != sec.x)
		{
//			mlx_get_color_value(prm->image->data_addr, new.color);
//			prm->image->data_addr[new.x * new.y] = new.color;
//            image_set_pixel(prm->image, new.x, new.y, new.color);
			mlx_pixel_put(prm->mlx_ptr, prm->win_ptr, new.x, new.y, new.color);
			get_next_coordinate(delta.x, direction.y, delta.y, &new.y);
			new.x += direction.x;
			new.color = find_gradient(new, frst, sec, delta);
		}
	else
		while (new.y != sec.y)
		{
//			prm->image->data_addr[new.x * new.y] = new.color;
//            image_set_pixel(prm->image, new.x, new.y, new.color);
			mlx_pixel_put(prm->mlx_ptr, prm->win_ptr, new.x, new.y, new.color);
			get_next_coordinate(delta.y, direction.x, delta.x, &new.x);
			new.y += direction.y;
			new.color = find_gradient(new, frst, sec, delta);
		}
}
