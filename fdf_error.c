/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:38:41 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 00:38:43 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		close_fdf(void *param)
{
	exit(0);
	return (0);
}

void		fdf_error(int code)
{
	if (code == NO_ARG)
		write(1, "fdf: missing map argument\nusage: ./fdf [filename]\n", 50);
	else if (code == ERROR_MAP)
		write(1, "fdf: error: invalid map\nusage: ./fdf [filename]\n", 48);
	else if (code == MISSING_MAP)
		write(1, "fdf: error: missing map\nusage: ./fdf [filename]\n", 48);
	else if (code == NOT_A_MAP)
		write(1, "fdf: error: argument is not a map\nusage: ./fdf [filename]\n", 58);
	else
		return ;
	exit(0);
}
