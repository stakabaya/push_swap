/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:30:22 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/13 23:32:11 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <push_swap.h>

int	add_list(t_lists *lists, int num)
{
	t_node_type	*node;
	t_node_type	*tail;
	t_node_type	*head;

	head = lists->a_list;
	tail = search_tail(head);
	node = malloc(sizeof(t_node_type));
	if (!node)
		return (0);
	node->value = num;
	node->next = head;
	node->prev = tail;
	tail->next = node;
	head->prev = node;
	return (1);
}

void	ft_free_flag(char **ptr, int flag)
{
	if (flag)
	{
		while (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
			ptr++;
		}
	}
}

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
			free(node->op);
			node->op = NULL;
			free(node);
			node = tmp;
		}
		free(node->op);
		node->op = NULL;
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
