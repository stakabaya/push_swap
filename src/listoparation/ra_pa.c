/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:20:48 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 13:35:53 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_node_type *head, t_opcomm *oplst, char *com)
{
	add_tail(head, head->next->value);
	delete_node(head->next);
	if (!strcmp(com, "ra"))
		op_add_tail(oplst, "ra");
	else if (!strcmp(com, "rb"))
		op_add_tail(oplst, "rb");
}

void	rotate_rev(t_node_type *head, t_opcomm *oplst, char *com)
{
	add_beginning(head, head->prev->value);
	delete_node(head->prev);
	if (!strcmp(com, "rra"))
		op_add_tail(oplst, "rra");
	else if (!strcmp(com, "rrb"))
		op_add_tail(oplst, "rrb");
}

void	push_a(t_node_type *a_list, t_node_type *b_list, t_opcomm *oplst)
{
	t_node_type	*a_head;
	t_node_type	*b_head;

	a_head = a_list->next;
	b_head = b_list->next;
	add_beginning(a_list, b_head->value);
	delete_node(b_head);
	op_add_tail(oplst, "pa");
}

void	push_b(t_node_type *a_list, t_node_type *b_list, t_opcomm *oplst)
{
	t_node_type	*a_head;
	t_node_type	*b_head;

	a_head = a_list->next;
	b_head = b_list->next;
	add_beginning(b_list, a_head->value);
	delete_node(a_head);
	op_add_tail(oplst, "pb");
}
