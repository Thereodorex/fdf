/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:04:52 by hchau             #+#    #+#             */
/*   Updated: 2019/12/27 15:04:55 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_count_line(t_node *node, int interval, int indent_x, int indent_y)
{
	int			i;
	static int	j = 0;

	i = 0;
	while (node)
	{
		node->current.x = i;
		node->prime = node->current;
		node->current.x = i * interval + indent_x;
		node->current.y = j * interval + indent_y;
		node = node->right;
		i++;
	}
	j++;
	return (i);
}

int		count_figure_interval(int count_coord, int *window_max)
{
	int		interval;

	while ((*window_max % (count_coord - 1)) != 0)
		*window_max = *window_max - 1;
	if (*window_max == 0)
		return (2);
	interval = (*window_max / (count_coord - 1));
	return (interval);
}

int		count_interval(t_node *node, int *x_indent, int *y_indent)
{
	int		x_max;
	int		y_max;
	int		interval;
	int		max_leight;

	max_leight = SIZE_WINDOW - (*x_indent * 2);
	x_max = count_scale_x(node);
	y_max = count_scale_y(node);
	if (x_max > y_max)
	{
		interval = count_figure_interval(x_max, &max_leight);
		*x_indent = (SIZE_WINDOW - max_leight) / 2;
		*y_indent = *x_indent + interval * (x_max - y_max) / 2;
		return (interval);
	}
	interval = count_figure_interval(y_max, &max_leight);
	*y_indent = (SIZE_WINDOW - max_leight) / 2;
	*x_indent = *y_indent + interval * (y_max - x_max) / 2;
	return (interval);
}

void	figure_scale(t_node *node, t_coord *indent, t_coord *scale)
{
	int		max;
	int		cur;
	int		interval;

	scale->z = count_scale_z(node, SIZE_WINDOW);
	max = count_scale_x(node);
	indent->x = INDENT;
	indent->y = INDENT;
	interval = count_interval(node, &indent->x, &indent->y);
	while (node)
	{
		if ((cur = get_count_line(node, interval, indent->x, indent->y)) != max)
		{
			clear_node(&node);
			fdf_error(ERROR_MAP);
		}
		node = node->down;
	}
	scale->y = interval;
	scale->x = interval;
}
