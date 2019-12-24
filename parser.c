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

void		parse_node(t_node *prev, t_node *current, char *ptr)
{

}

t_node		*parse_line(t_node *prev, t_node *current, char *ptr)
{
	//
	//принять текст
	//записать целую линию
	//вызвать себя же: пред - список
	current = (t_node *)malloc(sizeof(t_node));
	current->right = NULL;
	current->down = NULL;
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
	head = parse_line(NULL, head, (char *)text);
	printf("%s", text);
	close(fd);
	return head;
}