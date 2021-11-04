/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:18 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 16:55:35 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

int	is_sorted(t_node_type *list)
{
	t_node_type		*node;
	int				num;

	node = list->next;
	num = node->value;
	while (node != list)
	{
		if (num > node->value)
		{
			return (0);
		}
		num = node->value;
		node = node->next;
	}
	return (1);
}

void	check_dup(t_node_type *list)
{
	t_node_type	*node;
	t_node_type	*node_next;
	int			value;

	node = list->next;
	while (node != list)
	{
		value = node->value;
		node_next = node->next;
		while (node_next != list)
		{
			if (value == node_next->value)
				puts_errmsg_exit();
			node_next = node_next->next;
		}
		node = node->next;
	}
}

void	six_args(t_node_type *a, t_node_type *b, int ac, t_opcomm *oplst)
{
	int			min;
	int			max;
	int			i;

	i = ac;
	while (i > 3)
	{
		search_min_max(&min, &max, a);
		while (a->next->value != min)
			rotate(a, oplst, "ra");
		push_b(a, b, oplst);
		i--;
	}
	three_args(a, oplst, "a");
	while (b->next != b)
	{
		push_a(a, b, oplst);
	}
}

void	sortlst(t_lists *lists, int argc)
{
	check_dup(lists->a_list);
	if (argc == 1 || is_sorted(lists->a_list))
		end_program(lists);
	else if (argc == 2)
		swap_a(lists->a_list, lists->opcom_list);
	else if (argc == 3)
		three_args(lists->a_list, lists->opcom_list, "a");
	else if (argc <= 6)
		six_args(lists->a_list, lists->b_list, argc, lists->opcom_list);
	else if (argc > 6)
		more_args(lists);
}
