/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:14:06 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:14:08 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int		get_color(char *ptr)
{
	int		res;
	int		count;

	count = 0;
	while (*ptr && *ptr != ' ')
	{
		if (*ptr >= '0' && *ptr <= '9')
			res = res * 16 + *ptr - '0';
		else if (*ptr >= 'A' && *ptr <= 'F')
			res = res * 16 + *ptr - 'A' + 10;
		else if (*ptr >= 'a' && *ptr <= 'f')
			res = res * 16 + *ptr - 'a' + 10;
		else
			break ;
		ptr--;
		count++;
	}
	if (*ptr != 'x' || *(ptr - 1) != '0' || count > 8)
		return (-1);
	return (res);
}

char			*record_color(char *ptr, int *color)
{
	int		res;
	char	*to_return;

	to_return = NULL;
	res = 0;
	ptr += 2;
	while (*ptr && *ptr != ' ' && *ptr != '\n')
		ptr++;
	*color = get_color(ptr - 1);
	return (*color == -1 ? ptr - 1 : ptr);
}
