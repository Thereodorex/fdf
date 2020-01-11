/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:02:48 by amargy            #+#    #+#             */
/*   Updated: 2019/12/08 16:02:50 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_map(t_param *param)
{
	t_node	*line;
	t_node	*node;

	line = param->map;
	while (line)
	{
		node = line;
		while (node)
		{
			if ((node->current.x < 0 && node->current.y < 0) ||
			(node->current.x >= SIZE_WINDOW && node->current.y >= SIZE_WINDOW))
				break ;
			if (node->down)
				put_line(node->current, node->down->current, param);
			if (node->right)
				put_line(node->current, node->right->current, param);
			node = node->right;
		}
		line = line->down;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			param->image->image, 0, 0);
	if (param->open_menu == 0)
		put_menu(param);
	clear_image(param->image, SIZE_WINDOW * SIZE_WINDOW * 4);
}

void	open_win(t_param *param, char *filename)
{
	ft_bzero(param, sizeof(t_param));
	param->max_size = SIZE_WINDOW;
	param->map = parse_file(filename);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->max_size,
			param->max_size, filename);
}

int		main(int argc, char **argv)
{
	t_param		param;

	if (argc == 1)
		fdf_error(NO_ARG);
	open_win(&param, argv[1]);
	create_img(&param);
	figure_scale(param.map, &param.indent, &param.scale);
	if (param.map->current.color != 0x00FFFF00
	&& param.map->current.color != 0x00FF00FF)
		param.high_base_color = -1;
	fill_menu(&param);
	print_map(&param);
	mlx_hook(param.win_ptr, 2, 0, key_press, &param);
	mlx_hook(param.win_ptr, 17, 0, close_fdf, &param);
	mlx_hook(param.win_ptr, 4, 0, mouse_scroll, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
