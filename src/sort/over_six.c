/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:08:21 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 17:03:05 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

void	search_min_half(int *min, t_node_type *list, int *half, int *count)
{
	t_node_type		*node;

	node = list->next;
	*min = node->value;
	*half = 0;
	*count = 0;
	while (node != list)
	{
		if (*min > node->value)
			*min = node->value;
		*half += (int)node->value;
		node = node->next;
		*count = *count + 1;
	}
	if (*count == 0)
		return ;
	*half = *half / *count;
}

void	div_low_half(t_lists *lists, int *count)
{
	int			min;
	int			half;
	int			i;

	search_min_half(&min, lists->a_list, &half, count);
	i = *count;
	while (i)
	{
		if (lists->a_list->next->value <= half)
		{
			push_b(lists->a_list, lists->b_list, lists->opcom_list);
		}
		else
			rotate(lists->a_list, lists->opcom_list, "ra");
		i--;
	}
}

void	move_chunk(t_lists *lists, int *count, t_node_type *chunklst)
{
	int			min;
	int			half;

	search_min_half(&min, lists->a_list, &half, count);
	while (lists->a_list->next->value != min)
	{
		push_b(lists->a_list, lists->b_list, lists->opcom_list);
		if (chunklst->next != chunklst)
		{
			if (lists->b_list->next->value == chunklst->next->value)
			{
				delete_node(chunklst->next);
				break ;
			}
		}
	}
}

void	div_up_half(t_lists *lists, int *count, t_node_type *chunklst)
{
	int			min;
	int			half;
	int			flag;
	int			i;

	flag = 0;
	search_min_half(&min, lists->b_list, &half, count);
	i = *count;
	while (i)
	{
		if (lists->b_list->next->value > half)
		{
			push_a(lists->a_list, lists->b_list, lists->opcom_list);
			(*count)--;
			if (flag == 0)
			{
				add_beginning(chunklst, lists->a_list->next->value);
				flag = 1;
			}
		}
		else
			rotate(lists->b_list, lists->opcom_list, "rb");
		i--;
	}
}

void	more_args(t_lists *lists)
{
	int			min;
	int			half;
	int			count;
	t_node_type	chunk_list;

	chunk_list.next = &chunk_list;
	chunk_list.prev = &chunk_list;
	chunk_list.value = 0;
	div_low_half(lists, &count);
	while (1)
	{
		search_min_half(&min, lists->b_list, &half, &count);
		while (count > 3)
			div_up_half(lists, &count, &chunk_list);
		three_args(lists->b_list, lists->opcom_list, "b");
		while (lists->b_list->next != lists->b_list)
		{
			push_a(lists->a_list, lists->b_list, lists->opcom_list);
			rotate(lists->a_list, lists->opcom_list, "ra");
		}
		if (is_sorted(lists->a_list))
			break ;
		move_chunk(lists, &count, &chunk_list);
	}
}
