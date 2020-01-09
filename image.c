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

#include "header.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	a;
	char	*my_s;

	a = 0;
	my_s = (char *)s;
	while (a < n)
		my_s[a++] = '\0';
}

void	clear_image(t_image *image)
{
	ft_bzero(image->data_addr, SIZE_WINDOW * SIZE_WINDOW *
								(image->bits_per_pixel / 8));
}

void		image_set_pixel(t_image *image, int x, int y, int color)
{
	int		i;

	i = 0;
//    if (x < 0 || x >= SIZE_WINDOW || y < 0 || y >= SIZE_WINDOW)
//        return ;
	while (i < SIZE_WINDOW * SIZE_WINDOW / 4)
	{
		*(int *)(image->data_addr + ((i))) = 0x00FFFF00;
		i += 4;
	}
	//*(int *)(image->data_addr + ((x + y * image->size_line) * image->bits_per_pixel)) = color;
}

void		create_img(t_param param)
{
	t_image		*image;

	param.image = (t_image *)malloc(sizeof(t_image));
	param.image->image = mlx_new_image(param.mlx_ptr, SIZE_WINDOW, SIZE_WINDOW);
	param.image->data_addr = mlx_get_data_addr(param.image->image,
											   &(param.image->bits_per_pixel),
											   &(param.image->size_line),
											   &(param.image->endian));
}