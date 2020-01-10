/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:10:31 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:10:32 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_high(int keycode, t_param *param)
{
	if (keycode == 18)
		param->high_base_color = 0x0;
	else if (keycode == 19)
		param->high_base_color = 0xcccccc;
	else if (keycode == 20)
		param->high_base_color = -0x00FF00;
	else if (keycode == 21)
		param->high_base_color = -0xFF00FF;
	else if (keycode == 23)
		param->high_base_color = 0x0000FF;
	else
		return (0);
	return (1);
}

int		key_color(int keycode, t_param *param)
{
	if (param->high_base_color != -1)
	{
		if ((get_high(keycode, param)) == 0)
			return (0);
	}
	if (keycode == 18)
		param->base_color = 0x0;
	else if (keycode == 19)
		param->base_color = -0x0000AEEE;
	else if (keycode == 20)
		param->base_color = -0x00AA1111;
	else if (keycode == 21)
		param->base_color = -0x002000BB;
	else if (keycode == 23)
		param->base_color = 0x00117171;
	else
		return (0);
	return (1);
}
