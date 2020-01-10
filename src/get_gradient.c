/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:16:24 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:16:26 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

double			percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				find_gradient(t_coord current, t_coord start,
												t_coord end, t_coord delta)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		perc = percent(start.x, end.x, current.x);
	else
		perc = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, perc);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}
