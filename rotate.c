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
// 	node->current.x = (double)x * cos(param->z_rot) - (double)y * sin(param->z_rot) + SIZE_WINDOW / 2;
// 	node->current.y = (double)x * sin(param->z_rot) + (double)y * cos(param->z_rot) + SIZE_WINDOW / 2;
// }

// void	rotate_node(t_node *node, t_param *param)
// {
// 	int		x;
// 	int		y;
// 	int		z;

// 	x = node->prime.x - SIZE_WINDOW / 2;
// 	y = node->prime.y - SIZE_WINDOW / 2;
// 	z = node->prime.z;

// 	node->current.x = x;
// 	node->current.y = y;


// 	// node->current.y = (double)y * cos(param->x_rot) + (double)z * sin(param->x_rot);
// 	// node->current.z = (double)z * cos(param->x_rot) - (double)y * sin(param->x_rot);	

// 	// node->current.x = (double)x * cos(param->y_rot) + (double)node->current.z * sin(param->y_rot);
// 	// node->current.z = (double)node->current.z * cos(param->y_rot) - (double)x * sin(param->y_rot);

// 	node->current.x = (double)node->current.x * cos(param->z_rot) - (double)node->current.y  * sin(param->z_rot) + SIZE_WINDOW / 2;
// 	node->current.y = (double)x * sin(param->z_rot) + (double)y  * cos(param->z_rot) + SIZE_WINDOW / 2;

// 	node->current.x += param->x_move;
// 	node->current.y += param->y_move;

// }

void	rotate_node(t_node *node, t_param *param)
{
	int		x;
	int		y;
	int		z;

	x = node->prime.x - SIZE_WINDOW / 2;
	y = node->prime.y - SIZE_WINDOW / 2;
	z = node->prime.z;

	node->current.x = x;
	node->current.y = y;

	node->current.y = (double)y * cos(param->x_rot) + (double)z * sin(param->x_rot);
	node->current.z = (double)z * cos(param->x_rot) - (double)y * sin(param->x_rot);

	y = node->current.y;
	z = node->current.z;
		x = node->current.x;

	node->current.x = (double)x * cos(param->z_rot) - (double)y  * sin(param->z_rot);
	node->current.y = (double)x * sin(param->z_rot) + (double)y  * cos(param->z_rot);

	x = node->current.x;
	y = node->current.y;
	z = node->current.z;

	node->current.x = (double)x * cos(param->y_rot) + (double)z * sin(param->y_rot);
	node->current.z = (double)z * cos(param->y_rot) - (double)x * sin(param->y_rot);

	node->current.x += param->x_move + SIZE_WINDOW / 2;
	node->current.y += param->y_move + SIZE_WINDOW / 2;

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