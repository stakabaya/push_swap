/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcomlst_oparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:26:39 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 13:42:19 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	op_add_tail(t_opcomm *head, char *command)
{
	t_opcomm	*node;
	t_opcomm	*tail;

	tail = opsearch_tail(head);
	node = malloc(sizeof(t_opcomm));
	if (node == NULL)
		puts_errmsg_exit();
	node->op = strdup(command);
	if (node->op == NULL)
		puts_errmsg_exit();
	node->next = NULL;
	tail->next = node;
	return (1);
}
