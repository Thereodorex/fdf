/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:27:48 by hchau             #+#    #+#             */
/*   Updated: 2020/01/11 17:27:50 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_return(char *dest, char const *src)
{
	size_t		a;
	size_t		len;

	a = 0;
	if (dest != src)
	{
		len = ft_strlen(src);
		while (src[a] && a < len)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (dest + a);
}
