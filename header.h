/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:02:31 by jcorwin           #+#    #+#             */
/*   Updated: 2019/12/08 16:02:35 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		current_x;
	int		current_y;
	int		mouse_pressed;
}				t_param;