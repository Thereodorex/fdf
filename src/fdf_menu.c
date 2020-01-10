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

void	get_angle_str(char *str, double angle, t_param *param, int y)
{
	char	*extra;
	char	*new;

	extra = lf_conversion((long double)angle);
	new = ft_strjoin(str, extra);
	ft_strdel(&extra);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, y,
				0x00FFFFFF, new);
	ft_strdel(&new);
}

void	write_rest_menu(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 380,
				0x00FFFFFF, "h - close/open");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 420,
				0x00FFFFFF, "scale z:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 440,
				0x00FFFFFF, "z - grow up");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 460,
				0x00FFFFFF, "x - grow down");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 500,
				0x00FFFFFF, "set default:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 520,
				0x00FFFFFF, "space");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 1120,
				0x00FFFFFF, "Mouse:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 1160,
				0x00FFFFFF, "zoom:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 1180,
				0x00FFFFFF, "scroll up/down");
	get_angle_str("X = ", param->x_rot, param, 50);
	get_angle_str("Y = ", param->y_rot, param, 70);
	get_angle_str("Z = ", param->z_rot, param, 90);
}

void	write_menu(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 100,
				0x00FFFFFF, "Press button:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 140,
				0x00FFFFFF, "rotate:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 160,
				0x00FFFFFF, "q & e - rotate Z");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 180,
				0x00FFFFFF, "a & d - rotate Y");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 200,
				0x00FFFFFF, "w & s - rotate X");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 240,
				0x00FFFFFF, "move:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 260,
				0x00FFFFFF, "     < || >");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 260,
				0x00FFFFFF, "use    ^_");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1075, 260,
				0x00FFFFFF, "     -   - keys");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 300,
				0x00FFFFFF, "change color:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 320,
				0x00FFFFFF, "1, 2, 3, 4, 5");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1070, 360,
				0x00FFFFFF, "menu:");
	write_rest_menu(param);
}

void	put_menu(t_param *param)
{
	int		i;

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
