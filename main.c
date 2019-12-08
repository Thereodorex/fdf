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

#include <stdlib.h>
#include "mlx.h"
#include "header.h"

#define ESCAPE 53

int close(void *param)
{
    exit(0);
    return (0);
}

int key_press(int keycode, void *param)
{
    if (keycode == ESCAPE)
        exit(0);
    return (0);
}

int mouse_move(int x, int y, t_param *param)
{
    if (param->mouse_pressed)
        mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
        // printf("%d   %d\n", x, y);
    return (0);
}

int mouse_press(int button, int x, int y, t_param *param)
{
    if (button == 1) {
        param->mouse_pressed = 1;
        // mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
    }
    return (0);
}

int mouse_release(int button, int x, int y, t_param *param)
{
    if (button == 1) {
        param->mouse_pressed = 0;
    }
    return (0);
}

void    map_init(t_param *param, int **map, int x_len, int y_len)
{
    int     x;
    int     y;

    y = -1;
    while (++y < y_len)
    {
        x = -1;
        while (++x < x_len)
        {
            mlx_pixel_put(param->mlx_ptr, param->win_ptr, x * 10, y * 10, 0xFFFFFF);
        }
    }
}

int main()
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_param     param;
    int         coords[7][7];

    param.mouse_pressed = 0;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_start");
    param.win_ptr = win_ptr;
    param.mlx_ptr = mlx_ptr;
    map_init(&param, (int**) coords, 7, 7);
    // mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_hook(win_ptr, 3, 0, key_press, NULL);
    mlx_hook(win_ptr, 17, 0, close, NULL);
    mlx_hook(win_ptr, 4, 0, mouse_press, &param);
    mlx_hook(win_ptr, 5, 0, mouse_release, &param);
    mlx_hook(win_ptr, 6, 0, mouse_move, &param);
    mlx_loop(mlx_ptr);
    return (0);
}
