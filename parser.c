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

#include "header.h"

char		*get_num(char *ptr, t_coord *res)
{
	int		sign;

	res->z = 0;
	while (*ptr == ' ')
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else
		sign = 1;
	while (*ptr != ' ' && *ptr != '\n')
	{
		//   воткнуть валидацию
		res->z = res->z * 10 + *ptr - '0';
		res->color = 0xffffff;//   воткнуть цвет
		ptr++;
	}
	res->z *= sign;
	return (ptr);
}

char		*parse_node(t_node *left, t_node *up, t_node *current, char *ptr)
{
	if (!current)
		current = (t_node *)malloc(sizeof(t_node));
	current->down = NULL;
	ptr = get_num(ptr, &current->current);
	if (left)
	{
		left->right = current;
		current->current.x = left->current.x + 1;
	}
	else
		current->current.x = 0;
	if (up)
	{
		up->down = current;
		current->current.y = up->current.y + 1;
	}
	else
		current->current.y = 0;
	if (*ptr == '\n')
	{
		current->right = NULL;
		return (ptr + 1);
	}
	current->prime = current->current;
	return (parse_node(current, up ? up->right : NULL, NULL, ptr));
}

void		print_line(t_node *line)
{
	while (line)
	{
		printf("%d ", line->current.z);
		line = line->right;
	}
}		

void		print(t_node *head)
{
	while (head)
	{
		print_line(head);
		printf("\n");
		head = head->down;
	}
}

t_node		*parse_line(t_node *up, char *ptr)
{
	//
	//принять текст
	//записать целую линию
	//вызвать себя же: пред - список
	t_node		*start_line;

	start_line = (t_node *)malloc(sizeof(t_node));
	ptr = parse_node(NULL, up, start_line, ptr);
	print(start_line);
	if (*ptr != '\0')
		start_line->down = parse_line(start_line, ptr);
	else
		start_line->down = NULL;
	return start_line;
}

t_node		*parse_file(char *filename)
{
	t_node		*head;
	int			fd;
	char		text[100000];
	int			len;

	head = NULL;
	fd = open(filename, O_RDONLY);
	len = read(fd, text, 100000);
	text[len] = '\0';
	head = parse_line(NULL, (char *)text);
	// printf("%s", text);
	close(fd);
	return head;
}