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

void	print_map(t_param *param)
{
	t_node	*line;
	t_node	*node;
	int 		k;

	k = 0;
	line = param->map;
	while (line)
	{
		node = line;
		while (node)
		{
			
			if (node->down)
				put_line(node->current, node->down->current, param);
			if (node->right)
				put_line(node->current, node->right->current, param);
			node = node->right;
			k += 0x22222222;
		}
		line = line->down;
	}
}

int     main(int argc, char **argv)
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_param     param;

    t_coord f;
	t_coord s;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, SIZE_WINDOW, SIZE_WINDOW, "mlx_start");
    param.win_ptr = win_ptr;
    param.mlx_ptr = mlx_ptr;
    f.x = 0;
	f.y = 0;
	s.x = 10;
	s.y = 0;
	f.color = 0xFF00FF;
    // put_line(f, s, &param);
    // map_init(&param, (int**) coords, 7, 7);
    // mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	param.x_rot = 0;
	param.y_rot = 0;
	param.z_rot = 0;
	param.x_move = 0;
	param.y_move = 0;
	param.map = parse_file(argv[1]);
	figure_scale(param.map);
	print_map(&param);
    mlx_hook(win_ptr, 2, 0, key_press, &param);
    mlx_hook(win_ptr, 17, 0, close_fdf, &param);
    mlx_hook(win_ptr, 4, 0, mouse_press, &param);
    mlx_hook(win_ptr, 5, 0, mouse_release, &param);
    mlx_hook(win_ptr, 6, 0, mouse_move, &param);
    mlx_loop(mlx_ptr);
    return (0);
}
