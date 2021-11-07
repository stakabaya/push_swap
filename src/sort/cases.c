/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:35:16 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/07 22:18:53 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <push_swap.h>

void	case_one(t_lists *lists, char *com)
{
	if (!ft_strcmp(com, "a"))
		swap_a(lists);
	else
		swap_b(lists);
}

void	case_two(t_lists *lists, char *com)
{
	if (!ft_strcmp(com, "a"))
	{
		swap_a(lists);
		rotate_rev(lists->a_list, lists, "rra");
	}
	else
	{
		swap_b(lists);
		rotate_rev(lists->b_list, lists, "rrb");
	}
}

void	case_three(t_lists *lists, char *com)
{
	if (!ft_strcmp(com, "a"))
		rotate(lists->a_list, lists, "ra");
	else
		rotate(lists->b_list, lists, "rb");
}

void	case_four(t_lists *lists, char *com)
{
	if (!ft_strcmp(com, "a"))
	{
		swap_a(lists);
		rotate(lists->a_list, lists, "ra");
	}
	else
	{
		swap_b(lists);
		rotate(lists->b_list, lists, "rb");
	}
}

void	case_five(t_lists *lists, char *com)
{	
	if (!ft_strcmp(com, "a"))
		rotate_rev(lists->a_list, lists, "rra");
	else
		rotate_rev(lists->b_list, lists, "rrb");
}
