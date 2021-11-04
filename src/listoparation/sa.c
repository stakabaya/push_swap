/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:20:52 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 13:34:52 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	swap_a(t_node_type *list, t_opcomm *oplst)
{
	t_node_type	*a;
	t_node_type	*b;

	a = list->next;
	b = a->next;
	swap_node(a, b);
	op_add_tail(oplst, "sa");
}

void	swap_b(t_node_type *list, t_opcomm *oplst)
{
	t_node_type	*a;
	t_node_type	*b;

	a = list->next;
	b = a->next;
	swap_node(a, b);
	op_add_tail(oplst, "sb");
}
