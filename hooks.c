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

int close_fdf(void *param)
{
    exit(0);
    return (0);
}

int key_press(int keycode, t_param *param)
{
    if (keycode == ESCAPE)
        exit(0);
    else if (keycode == 12)
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
    else if (keycode == 123)
        param->x_move -= 10;
    else if (keycode == 124)
        param->x_move += 10;
    else if (keycode == 125)
        param->y_move += 10;
    else if (keycode == 126)
        param->y_move -= 10;
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    rotate_map(param);
    print_map(param);
    // param->x_move = 0;
	// param->y_move = 0;
    printf("%d\n", keycode);
    return (0);
}

int mouse_move(int x, int y, t_param *param)
{
    // if (param->mouse_pressed)
    //     mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
        // printf("%d   %d\n", x, y);
    return (0);
}

int mouse_press(int button, int x, int y, t_param *param)
{
    // if (button == 1) {
    //     param->mouse_pressed = 1;
    //     // mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
    // }
    return (0);
}

int mouse_release(int button, int x, int y, t_param *param)
{
    // if (button == 1) {
    //     param->mouse_pressed = 0;
    // }
    return (0);
}