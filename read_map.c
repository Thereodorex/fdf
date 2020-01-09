/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:11:37 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:11:39 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*remalloc_map(char **str, int old_size, int new_size)
{
	char			*new_str;
	int				i;
	unsigned long	*ptr1;
	unsigned long	*ptr2;

	new_str = (char *)malloc(new_size + 1);
	i = 0;
	ptr1 = (unsigned long *)*str;
	ptr2 = (unsigned long *)new_str;
	while ((unsigned long)(ptr1 - (unsigned long)*str)
						< (unsigned long)(old_size - 8))
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
	}
	i = ptr1 - (unsigned long *)*str;
	while (i < old_size)
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i] = '\0';
	free(*str);
	return (new_str);
}

char		*read_file(int fd)
{
	char	*str;
	int		size;
	int		len;
	int		old_size;

	size = 100;
	old_size = 100;
	len = 0;
	str = (char *)malloc(size + 1);
	if ((len = read(fd, str, 0)) < 0)
	{
		free(str);
		return (NULL);
	}
	while ((len = read(fd, str + len, old_size)) == old_size)
	{
		str = remalloc_map(&str, len + old_size, size * 2);
		len = size;
		old_size = size;
		size *= 2;
	}
	str[len + old_size] = '\0';
	return (str);
}
