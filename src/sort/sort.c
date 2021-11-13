/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:18 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/13 19:06:50 by stakabay         ###   ########.fr       */
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

void	check_dup(t_lists *lists)
{
	t_node_type	*node;
	t_node_type	*node_next;
	int			value;

	node = lists->a_list->next;
	while (node != lists->a_list)
	{
		value = node->value;
		node_next = node->next;
		while (node_next != lists->a_list)
		{
			if (value == node_next->value)
				error_end_program(lists);
			node_next = node_next->next;
		}
		node = node->next;
	}
}

void	six_args(t_lists *lists, int ac)
{
	int			min;
	int			max;
	int			i;

	i = ac;
	while (i > 3)
	{
		search_min_max(&min, &max, lists->a_list);
		while (lists->a_list->next->value != min)
		{
			if (lists->a_list->next->next->value == min || \
				lists->a_list->next->next->next->value == min)
				rotate(lists->a_list, lists, "ra");
			else
				rotate_rev(lists->a_list, lists, "rra");
		}
		push_b(lists);
		i--;
	}
	three_args(lists->a_list, lists, "a");
	while (lists->b_list->next != lists->b_list)
	{
		push_a(lists);
	}
}

void	sortlst(t_lists *lists, int argc)
{
	check_dup(lists);
	if (argc == 1 || is_sorted(lists->a_list))
		end_program(lists);
	else if (argc == 2)
		swap_a(lists);
	else if (argc == 3)
		three_args(lists->a_list, lists, "a");
	else if (argc <= 6)
		six_args(lists, argc);
	else if (argc > 6)
		more_args(lists);
}
