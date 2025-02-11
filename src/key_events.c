/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:55:09 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 00:55:10 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		key_exit(int keycode, t_param *param)
{
	if (keycode == ESCAPE)
	{
		clear_node(&(param->map));
		mlx_destroy_image(param->mlx_ptr, param->image->data_addr);
		free(param->image);
		clear_image(param->menu, SIZE_MENU * SIZE_WINDOW * 4);
		mlx_destroy_image(param->mlx_ptr, param->menu->data_addr);
		free(param->menu);
		exit(0);
	}
	return (0);
}

int		key_rot(int keycode, t_param *param)
{
	if (keycode == 12)
		param->z_rot -= 0.0174533;
	else if (keycode == 14)
		param->z_rot += 0.0174533;
	else if (keycode == 1)
		param->x_rot -= 0.0174533;
	else if (keycode == 13)
		param->x_rot += 0.0174533;
	else if (keycode == 0)
		param->y_rot -= 0.0174533;
	else if (keycode == 2)
		param->y_rot += 0.0174533;
	else
		return (0);
	return (1);
}

int		key_move(int keycode, t_param *param)
{
	if (keycode == 123)
		param->x_move -= 10;
	else if (keycode == 124)
		param->x_move += 10;
	else if (keycode == 125)
		param->y_move += 10;
	else if (keycode == 126)
		param->y_move -= 10;
	else
		return (0);
	return (1);
}

int		key_default(int keycode, t_param *param)
{
	if (keycode != 49)
		return (0);
	param->x_move = 0;
	param->y_move = 0;
	param->scale.z = count_scale_z(param->map, SIZE_WINDOW);
	param->high_base_color = param->high_base_color == -1 ? -1 : 0;
	param->base_color = 0;
	param->x_rot = 0;
	param->y_rot = 0;
	param->z_rot = 0;
	figure_scale(param->map, &param->indent, &param->scale);
	return (1);
}

int		key_size(int keycode, t_param *param)
{
	if (keycode == 69)
	{
		param->scale.y++;
		param->scale.x++;
	}
	else if (keycode == 78)
	{
		if (param->scale.x > 1)
		{
			param->scale.x--;
			param->scale.y--;
		}
	}
	else if (keycode == 6)
		param->scale.z++;
	else if (keycode == 7)
		param->scale.z--;
	else
		return (0);
	return (1);
}
