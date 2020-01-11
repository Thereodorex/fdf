/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:28:30 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:28:32 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int				count_scale_x(t_node *node)
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

int				count_scale_y(t_node *node)
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

static int		check_count(int *count, int i, int check)
{
	int		c;

	c = 0;
	if (i >= 10000)
		return (0);
	while (c <= i)
	{
		if (count[c] == check)
			return (0);
		c++;
	}
	return (1);
}

int				count_max_z(t_node *node)
{
	int			count[10000];
	int			i;
	t_node		*line;

	i = 0;
	count[0] = node->prime.z;
	while (node)
	{
		line = node;
		while (line)
		{
			if ((check_count(count, i, line->prime.z)) != 0)
				count[++i] = line->prime.z;
			line = line->right;
		}
		node = node->down;
	}
	return (i);
}

int				count_scale_z(t_node *node, int max_size)
{
	int		x;
	int		y;
	int		max_z;

	max_z = 0;
	x = count_scale_x(node);
	y = count_scale_y(node);
	max_size = max_size / 100;
	if (max_z >= max_size || max_z == 0)
		return (-1);
	return (max_size / max_z * -1);
}
