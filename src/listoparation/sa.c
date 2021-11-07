/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:20:52 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/05 17:51:57 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

void	swap_node(t_node_type *a, t_node_type *b)
{
	t_node_type	*tmp;

	b->prev->next = a;
	a->prev->next = b;
	tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;
	a->next->prev = b;
	b->next->prev = a;
	tmp = a->next;
	a->next = b->next;
	b->next = tmp;
}

void	swap_a(t_lists *lists)
{
	t_node_type	*current;
	t_node_type	*next;

	current = lists->a_list->next;
	next = current->next;
	swap_node(current, next);
	op_add_tail(lists, "sa");
}

void	swap_b(t_lists *lists)
{
	t_node_type	*current;
	t_node_type	*next;

	current = lists->b_list->next;
	next = current->next;
	swap_node(current, next);
	op_add_tail(lists, "sb");
}
