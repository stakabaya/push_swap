/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:30:22 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 16:54:36 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <push_swap.h>

void	clear_stack_list(t_node_type *head)
{
	t_node_type	*node;
	t_node_type	*tmp;

	if (head->next != head)
	{
		node = head->next;
		while (node->next != head)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		free(node);
		node = NULL;
	}
}

void	clear_opcomm_list(t_opcomm *head)
{
	t_opcomm	*node;
	t_opcomm	*tmp;

	if (head->next != NULL)
	{
		node = head->next;
		while (node->next != NULL)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		free(node);
		node = NULL;
	}
}

void	end_program(t_lists *lists)
{
	clear_opcomm_list(lists->opcom_list);
	clear_stack_list(lists->a_list);
	clear_stack_list(lists->b_list);
	exit(EXIT_SUCCESS);
}
