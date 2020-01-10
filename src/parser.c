/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:02:48 by jcorwin           #+#    #+#             */
/*   Updated: 2019/12/08 16:02:50 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char		*read_coord(char *ptr, t_coord *res, int sign)
{
	while ((*ptr >= '0' && *ptr <= '9') || *ptr == ',')
	{
		if (*ptr == ',')
		{
			ptr = record_color(ptr, &(res->color));
			break ;
		}
		res->z = res->z * 10 + *ptr - '0';
		if (res->z > 9 && sign == 1)
			res->color = 0x00FFFF00;
		ptr++;
	}
	return (ptr);
}

char		*get_num(char *ptr, t_coord *res)
{
	int		sign;

	res->z = 0;
	res->color = 0x00FF00FF;
	while (*ptr == ' ')
		ptr++;
	if (*ptr == '\0')
		return (NULL);
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else
		sign = 1;
	ptr = read_coord(ptr, res, sign);
	if (*ptr != ' ' && *ptr != '\n')
		return (NULL);
	while (*ptr == ' ')
		ptr++;
	res->z *= sign;
	return (ptr);
}

char		*parse_node(t_node *left, t_node *up, t_node *current, char *ptr)
{
	current = !(current) ? (t_node *)malloc(sizeof(t_node)) : current;
	current->down = NULL;
	if (!(ptr = get_num(ptr, &current->prime)))
		return (clear_node(&current));
	if (left)
	{
		left->right = current;
		current->prime.x = left->prime.x + 1;
	}
	else
		current->prime.x = 0;
	if (up)
	{
		up->down = current;
		current->prime.y = up->prime.y + 1;
	}
	else
		current->prime.y = 0;
	if (*ptr == '\n')
	{
		current->right = NULL;
		return (ptr + 1);
	}
	current->prime = current->prime;
	return (parse_node(current, up ? up->right : NULL, NULL, ptr));
}

t_node		*parse_line(t_node *up, char *ptr)
{
	t_node		*start_line;

	if (!ptr)
	{
		clear_node(&up);
		return (NULL);
	}
	start_line = (t_node *)malloc(sizeof(t_node));
	if (!(ptr = parse_node(NULL, up, start_line, ptr)))
	{
		clear_node(&start_line);
		return (NULL);
	}
	if (*ptr != '\0')
	{
		if (!(start_line->down = parse_line(start_line, ptr)))
		{
			clear_node(&start_line);
			return (NULL);
		}
	}
	else
		start_line->down = NULL;
	return (start_line);
}

t_node		*parse_file(char *filename)
{
	t_node		*head;
	int			fd;
	char		*text;
	int			len;

	head = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 3 || !(text = read_file(fd)))
	{
		if (fd != -1)
			close(fd);
		fdf_error(NOT_A_MAP);
	}
	if (!(head = parse_line(NULL, text)))
	{
		free(text);
		close(fd);
		fdf_error(ERROR_MAP);
	}
	close(fd);
	free(text);
	return (head);
}
