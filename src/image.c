/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:18:49 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:18:50 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			fill_menu(t_param *param)
{
	int		i;
	int		j;
	int		mask;

	i = 0;
	j = 0;
	mask = 0xFF000000;
	while (i < SIZE_MENU)
	{
		while (i < SIZE_MENU - 100 && mask > 0x88000000)
		{
			while (j < SIZE_WINDOW)
				image_set_pixel(&param->menu, i, j++, 0x00CCAAFF | mask);
			mask = mask - 0x01000000;
			j = 0;
			i++;
		}
		while (j < SIZE_WINDOW)
			image_set_pixel(&param->menu, i, j++, 0x88DDAAFF);
		j = 0;
		i++;
	}
	return (0);
}

void		clear_image(t_image *image, unsigned long size)
{
	ft_bzero(image->data_addr, size);
}

void		image_set_pixel(t_image **image, int x, int y, int color)
{
	int			i;
	t_image		*img;

	i = 0;
	img = *image;
	if (x < 0 || x >= SIZE_WINDOW || y < 0 || y >= SIZE_WINDOW)
		return ;
	*(int *)(img->data_addr + ((x * 4 + y * img->size_line))) = color;
}

void		create_img(t_param *param)
{
	t_image		*image;

	param->image = (t_image *)malloc(sizeof(t_image));
	param->image->image = mlx_new_image(param->mlx_ptr,
											SIZE_WINDOW, SIZE_WINDOW);
	param->image->data_addr = mlx_get_data_addr(param->image->image,
											&(param->image->bits_per_pixel),
											&(param->image->size_line),
											&(param->image->endian));
	clear_image(param->image, SIZE_WINDOW * SIZE_WINDOW * 4);
	param->menu = (t_image *)malloc(sizeof(t_image));
	param->menu->image = mlx_new_image(param->mlx_ptr, SIZE_MENU,
										SIZE_WINDOW);
	param->menu->data_addr = mlx_get_data_addr(param->menu->image,
											&(param->menu->bits_per_pixel),
											&(param->menu->size_line),
											&(param->menu->endian));
	clear_image(param->menu, SIZE_WINDOW * SIZE_MENU * 4);
}
