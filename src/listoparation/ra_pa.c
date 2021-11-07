/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:20:48 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/05 18:37:21 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

void	rotate(t_node_type *head, t_lists *lists, char *com)
{
	add_tail(head, lists, head->next->value);
	delete_node(head->next);
	if (!ft_strcmp(com, "ra"))
		op_add_tail(lists, "ra");
	else if (!ft_strcmp(com, "rb"))
		op_add_tail(lists, "rb");
}

void	rotate_rev(t_node_type *head, t_lists *lists, char *com)
{
	add_beginning(head, lists, head->prev->value);
	delete_node(head->prev);
	if (!ft_strcmp(com, "rra"))
		op_add_tail(lists, "rra");
	else if (!ft_strcmp(com, "rrb"))
		op_add_tail(lists, "rrb");
}

void	push_a(t_lists *lists)
{
	t_node_type	*b_head;

	b_head = lists->b_list->next;
	add_beginning(lists->a_list, lists, b_head->value);
	delete_node(b_head);
	op_add_tail(lists, "pa");
}

void	push_b(t_lists *lists)
{
	t_node_type	*a_head;

	a_head = lists->a_list->next;
	add_beginning(lists->b_list, lists, a_head->value);
	delete_node(a_head);
	op_add_tail(lists, "pb");
}
