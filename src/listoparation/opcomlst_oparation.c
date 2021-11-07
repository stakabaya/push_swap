/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcomlst_oparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:26:39 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/05 18:32:52 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

void	print_op_list(t_opcomm *head)
{
	t_opcomm	*node;

	node = head->next;
	while (node != NULL)
	{
		ft_putendl_fd(node->op, 1);
		node = node->next;
	}
}

t_opcomm	*opsearch_tail(t_opcomm *head)
{
	t_opcomm		*node;

	node = head;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

int	op_add_tail(t_lists *lists, char *command)
{
	t_opcomm	*node;
	t_opcomm	*tail;

	tail = opsearch_tail(lists->opcom_list);
	node = malloc(sizeof(t_opcomm));
	if (node == NULL)
		error_end_program(lists);
	node->op = ft_strdup(command);
	if (node->op == NULL)
		error_end_program(lists);
	node->next = NULL;
	tail->next = node;
	return (1);
}
