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
//соррян, не добавила дефайны в хедере на размер окна


int		count_scale_x(t_node *node)
{
	int		x;

	x = 0;
	while (node)
	{
		node = node->right;
		x++;
	}
	return (x);
}

int		count_scale_y(t_node *node)
{
	int		y;

	y = 0;
	while (node)
	{
		node = node->down;
		y++;
	}
	return (y);
}

void		get_count_line(t_node *node,  int interval, int indent_x, int indent_y)
{
	int			i;
	static int 	j;

	i = 0;
	while (node)
	{
		node->current.x = i * interval + indent_x;
		node->current.y = j * interval + indent_y;
		//цепляю ноду на прайм, надо закинуть при создании, привет
		// copy_in_prime(node);
		//пока цвет задаю здесь
		node->prime = node->current;
		node = node->right;
		i++;
	}
	j++;
}

int			count_interval(t_node *node, int *x_indent, int *y_indent)	//надо разбить, хуёво вышло
{
	int		x_max;
	int		y_max;
	int		interval;
	int 	max_leight;

	*x_indent = INDENT;
	*y_indent = INDENT;
	max_leight = SIZE_WINDOW - (*x_indent * 2);
	x_max = count_scale_x(node);
	y_max = count_scale_y(node);
	if (x_max > y_max)
	{
		while ((max_leight % (x_max - 1)) != 0)
			max_leight--;
		if (max_leight == 0)
			return (2);
		interval = (max_leight / (x_max - 1));
		*x_indent = (SIZE_WINDOW - max_leight) / 2;
		*y_indent = *x_indent + interval * (x_max - y_max) / 2;
		return (interval);
	}
	while ((max_leight % (y_max - 1)) != 0)
		max_leight--;
	if (max_leight == 0)
		return (2);
	interval = (max_leight / (y_max - 1));
	*y_indent = (SIZE_WINDOW - max_leight) / 2;
	*x_indent = *y_indent + interval * (y_max - x_max) / 2;
	return (interval);
}

void		figure_scale(t_node *node)
{
	int		indent_x;
	int		indent_y;
	int		i;
	int 	interval;

	i = 1;
	interval = count_interval(node, &indent_x, &indent_y);
	while (node)
	{
		get_count_line(node, interval, indent_x, indent_y);
		node = node->down;
	}
}