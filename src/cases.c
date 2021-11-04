/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:35:16 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/03 16:35:22 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

void	case_one(t_node_type *list, t_opcomm *oplst, char *com)
{
	if (!strcmp(com, "a"))
		swap_a(list, oplst);
	else
		swap_b(list, oplst);
}

void	case_two(t_node_type *list, t_opcomm *oplst, char *com)
{
	if (!strcmp(com, "a"))
	{
		swap_a(list, oplst);
		rotate_rev(list, oplst, "rra");
	}
	else
	{
		swap_b(list, oplst);
		rotate_rev(list, oplst, "rrb");
	}
}

void	case_three(t_node_type *list, t_opcomm *oplst, char *com)
{
	if (!strcmp(com, "a"))
		rotate(list, oplst, "ra");
	else
		rotate(list, oplst, "rb");
}

void	case_four(t_node_type *list, t_opcomm *oplst, char *com)
{
	if (!strcmp(com, "a"))
	{
		swap_a(list, oplst);	
		rotate(list, oplst, "ra");
	}
	else
	{
		swap_b(list, oplst);	
		rotate(list, oplst, "rb");
	}
}

void	case_five(t_node_type *list, t_opcomm *oplst, char *com)
{	
	if (!strcmp(com, "a"))
		rotate_rev(list, oplst, "rra");
	else
		rotate_rev(list, oplst, "rrb");
}