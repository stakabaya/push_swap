/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:33:26 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 13:38:50 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	three_args(t_node_type *list, t_opcomm *oplst, char *com)
{
	t_node_type		*node;
	int				min;
	int				max;

	search_min_max(&min, &max, list);
	node = list->next;
	if (node->next->value == min)
	{
		if (list->prev->value == max)
			case_one(list, oplst, com);
		else if (node->value == max)
			case_three(list, oplst, com);
	}
	else if (node->value == max)
		case_two(list, oplst, com);
	else if (node->next->value == max)
	{
		if (node->value == min)
			case_four(list, oplst, com);
		else
			case_five(list, oplst, com);
	}
}
