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

int		key_press(int keycode, t_param *param)
{
	if ((key_exit(keycode)) || (key_rot(keycode, param)) ||
			(key_move(keycode, param)) || (key_color(keycode, param))
			|| (key_size(keycode, param)))
		;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	rotate_map(param);
	print_map(param);
	printf("%d\n", keycode);
	return (0);
}

int		mouse_move(int x, int y, t_param *param)
{
	// if (param->mouse_pressed)
	//     mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
		// printf("%d   %d\n", x, y);
	return (0);
}

int		mouse_press(int button, int x, int y, t_param *param)
{
	// if (button == 1) {
	//     param->mouse_pressed = 1;
	//     // mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
	// }
	return (0);
}

int		mouse_release(int button, int x, int y, t_param *param)
{
	// if (button == 1) {
	//     param->mouse_pressed = 0;
	// }
	return (0);
}
