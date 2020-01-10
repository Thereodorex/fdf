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

int		key_press(int keycode, t_param *param)
{
	if ((key_exit(keycode, param)) || (key_rot(keycode, param)) ||
			(key_move(keycode, param)) || (key_color(keycode, param))
			|| (key_size(keycode, param)) || (key_default(keycode, param))
			|| (key_menu(keycode, param)))
		;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	rotate_map(param);
	print_map(param);
	printf("%d\n", keycode);
	return (0);
}

int		mouse_scroll(int button, int x, int y, t_param *param)
{
	if (button == 5)
	{
		param->scale.y++;
		param->scale.x++;
	}
	if (button == 4 && param->scale.y > 1)
	{
		param->scale.y--;
		param->scale.x--;
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	rotate_map(param);
	print_map(param);
	return (0);
}

int		mouse_move(int x, int y, t_param *param)
{
	return (0);
}

int		mouse_press(int button, int x, int y, t_param *param)
{
	return (0);
}

int		mouse_release(int button, int x, int y, t_param *param)
{
	return (0);
}
