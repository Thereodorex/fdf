/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:38:24 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 00:38:27 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	clear_node(t_node **arr)
{
	t_node	*temp;
	t_node	*temp_line;
	t_node	*temp_arr;

	while (*arr)
	{
		temp_arr = (*arr)->down;
		temp_line = *arr;
		while (temp_line)
		{
			temp = temp_line->right;
			free(temp_line);
			temp_line = temp;
		}
		*arr = temp_arr;
	}
}
