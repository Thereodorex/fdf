/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:02:48 by jcorwin           #+#    #+#             */
/*   Updated: 2019/12/08 16:02:50 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	rotate_node(t_node *node, t_param *param)
// {
// 	int		x;
// 	int		y;

// 	x = node->prime.x - SIZE_WINDOW / 2;
// 	y = node->prime.y - SIZE_WINDOW / 2;
// 	node->current.x = (double)node->prime.x * cos(param->z_rot) - (double)node->prime.y * sin(param->z_rot);
// 	node->current.y = (double)node->prime.x * sin(param->z_rot) + (double)node->prime.y * cos(param->z_rot);
// }

void	rotate_node(t_node *node, t_param *param)
{
	int		x;
	int		y;

	x = node->prime.x - SIZE_WINDOW / 2;
	y = node->prime.y - SIZE_WINDOW / 2;
	node->current.x = (double)x * cos(param->z_rot) - (double)y * sin(param->z_rot) + SIZE_WINDOW / 2;
	node->current.y = (double)x * sin(param->z_rot) + (double)y * cos(param->z_rot) + SIZE_WINDOW / 2;
}

void	rotate_map(t_param *param)
{
	t_node	*line;
	t_node	*node;

	line = param->map;
	while (line)
	{
		node = line;
		while (node)
		{
			rotate_node(node, param);
			node = node->right;
		}
		line = line->down;
	}
}