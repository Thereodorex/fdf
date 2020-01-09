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

	line = param->map;
    image_set_pixel(param->image, 0, 0, 0x00FFFFFF);
    mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
    		param->image->data_addr, 0, 0);
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
		}
		line = line->down;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			param->image->data_addr, 0, 0);
}

int     main(int argc, char **argv)
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_param     param;

	ft_bzero(&param, sizeof(t_param));
	param.max_size = SIZE_WINDOW;
	param.map = parse_file(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SIZE_WINDOW, SIZE_WINDOW, "mlx_start");
	param.win_ptr = win_ptr;
	param.mlx_ptr = mlx_ptr;
//	create_img(param);
	param.image = (t_image *)malloc(sizeof(t_image));
	param.image->image = mlx_new_image(param.mlx_ptr, SIZE_WINDOW, SIZE_WINDOW);
	param.image->data_addr = mlx_get_data_addr(param.image->image,
			&(param.image->bits_per_pixel),
			&(param.image->size_line),
			&(param.image->endian));
	figure_scale(param.map, &param.indent, &param.scale);
	if (param.map->current.color != 0x00FFFF00 && param.map->current.color != 0x00FF00FF)
		param.high_base_color = -1;
	print_map(&param);
    mlx_put_image_to_window(mlx_ptr, win_ptr, param.image->data_addr, 0, 0);
    mlx_hook(win_ptr, 2, 0, key_press, &param);
    mlx_hook(win_ptr, 17, 0, close_fdf, &param);
    mlx_hook(win_ptr, 4, 0, mouse_press, &param);
    mlx_hook(win_ptr, 5, 0, mouse_release, &param);
    mlx_hook(win_ptr, 6, 0, mouse_move, &param);
    mlx_loop(mlx_ptr);
    return (0);
}
