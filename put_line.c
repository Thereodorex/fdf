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

void			put_line(t_coord one, t_coord two, t_param *prm)
{
	t_coord		delta;
	t_coord		direction;
	t_coord		new;

	new = one;
	delta.x = two.x - one.x < 0 ? one.x - two.x : two.x - one.x;
	delta.y = two.y - one.y < 0 ? one.y - two.y : two.y - one.y;
	direction.y = two.y > one.y ? 1 : -1;
	direction.x = two.x > one.x ? 1 : -1;
	if (delta.y < delta.x)
		while (new.x != two.x)
		{
            image_set_pixel(&prm->image, new.x, new.y, new.color);
			get_next_coordinate(delta.x, direction.y, delta.y, &new.y);
			new.x += direction.x;
			new.color = find_gradient(new, one, two, delta);
		}
	else
		while (new.y != two.y)
		{
            image_set_pixel(&prm->image, new.x, new.y, new.color);
			get_next_coordinate(delta.y, direction.x, delta.x, &new.x);
			new.y += direction.y;
			new.color = find_gradient(new, one, two, delta);
		}
}
