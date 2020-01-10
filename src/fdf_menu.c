/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 01:00:08 by hchau             #+#    #+#             */
/*   Updated: 2020/01/11 01:00:10 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fill_menu(t_param *param)
{
	int		i;
	int		j;
	int		mask;

	i = 0;
	j = 0;
	mask = 0xFF000000;
	while (i < SIZE_MENU)
	{
		while (i < SIZE_MENU - 100 && mask > 0xAA000000)
		{
			while (j < SIZE_WINDOW)
				image_set_pixel(&param->menu, i, j++, 0x00FFFFFF | mask);
			mask = mask - 0x01000000;
			j = 0;
			i++;
		}
		while (j < SIZE_WINDOW)
			image_set_pixel(&param->menu, i, j++, 0xAAFFFFFF);
		j = 0;
		i++;
	}
	return (0);
}

void	write_rest_menu(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 320,
				0x00EEEEEE, "1, 2, 3, 4, 5");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 360,
				0x00EEEEEE, "menu:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 380,
				0x00EEEEEE, "h - close/open");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 420,
				0x00EEEEEE, "scale z:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 460,
				0x00EEEEEE, "z - grow up");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 480,
				0x00EEEEEE, "x - grow down");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 520,
				0x00EEEEEE, "set default:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 540,
				0x00EEEEEE, "space");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 1120,
				0x00EEEEEE, "Mouse:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 1160,
				0x00EEEEEE, "zoom:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 1180,
				0x00EEEEEE, "scroll up/down");
}

void	write_menu(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 100,
				0x00EEEEEE, "Press button:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 140,
				0x00EEEEEE, "rotate:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 160,
				0x00EEEEEE, "q & e - rotate Z");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 180,
				0x00EEEEEE, "a & d - rotate Y");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 200,
				0x00EEEEEE, "w & s - rotate X");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 240,
				0x00EEEEEE, "move:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 260,
				0x00EEEEEE, "     < || >");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 260,
				0x00EEEEEE, "use    ^_");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1075, 260,
				0x00EEEEEE, "     -   - keys");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 300,
				0x00EEEEEE, "change color:");
	write_rest_menu(param);
}

void	put_menu(t_param *param)
{
	int		i;
	int		j;

	i = SIZE_WINDOW - SIZE_MENU;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
							param->image->image, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
							param->menu->image, i, 0);
	write_menu(param);
}

int		key_menu(int keycode, t_param *param)
{
	if (keycode == 4)
		param->open_menu = param->open_menu == 1 ? 0 : 1;
	else
		return (0);
	return (1);
}
