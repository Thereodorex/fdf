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

#include "../includes/header.h"

void	scale_all(t_node *node, t_param *param)
{
	node->current.x = (node->prime.x * param->scale.x + param->indent.x)
			- SIZE_WINDOW / 2;
	node->current.y = (node->prime.y * param->scale.y + param->indent.y)
			- SIZE_WINDOW / 2;
	node->current.z = node->prime.z * param->scale.z;
}

void	prepare_cur_point(double *x, double *y, double *z, t_coord *coord)
{
	*x = (double)coord->x;
	*y = (double)coord->y;
	*z = (double)coord->z;
}

void	count_rotate_matrix(t_node *node, t_param *param)
{
	;
}

void	rotate_node(t_node *node, t_param *param)
{
	double		x;
	double		y;
	double		z;

	scale_all(node, param);
	prepare_cur_point(&x, &y, &z, &node->current);
	node->current.y = y * cos(param->x_rot) + z * sin(param->x_rot);
	node->current.z = z * cos(param->x_rot) - y * sin(param->x_rot);
	prepare_cur_point(&x, &y, &z, &node->current);
	node->current.x = x * cos(param->z_rot) - y * sin(param->z_rot);
	node->current.y = x * sin(param->z_rot) + y * cos(param->z_rot);
	prepare_cur_point(&x, &y, &z, &node->current);
	node->current.x = x * cos(param->y_rot) + z * sin(param->y_rot);
	node->current.z = z * cos(param->y_rot) - x * sin(param->y_rot);
	node->current.x += param->x_move + SIZE_WINDOW / 2;
	node->current.y += param->y_move + SIZE_WINDOW / 2;
	if (node->prime.z == 0 || param->high_base_color == -1)
		node->current.color = node->prime.color + param->base_color;
	if (node->prime.z != 0 && param->high_base_color != -1)
		node->current.color = node->prime.color + param->high_base_color;
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
