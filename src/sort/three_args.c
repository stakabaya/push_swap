/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:33:26 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/05 18:16:18 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

void	search_min_max(int *min, int *max, t_node_type *list)
{
	t_node_type		*node;

	node = list->next;
	*min = node->value;
	*max = node->value;
	while (node != list)
	{
		if (*min > node->value)
			*min = node->value;
		if (*max < node->value)
			*max = node->value;
		node = node->next;
	}
}

void	three_args(t_node_type *stack, t_lists *lists, char *com)
{
	t_node_type		*node;
	int				min;
	int				max;

	search_min_max(&min, &max, stack);
	node = stack->next;
	if (node->next->value == min)
	{
		if (stack->prev->value == max)
			case_one(lists, com);
		else if (node->value == max)
			case_three(lists, com);
	}
	else if (node->value == max)
		case_two(lists, com);
	else if (node->next->value == max)
	{
		if (node->value == min)
			case_four(lists, com);
		else
			case_five(lists, com);
	}
}
