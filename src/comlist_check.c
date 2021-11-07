/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comlist_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:17:36 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/05 09:54:56 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <push_swap.h>

void	delete_opnode_next(t_opcomm *opnode)
{
	t_opcomm	*tmp;

	tmp = opnode->next;
	opnode->next = tmp->next;
	free(tmp->op);
	tmp->op = NULL;
	free(tmp);
	tmp = NULL;
}

void	ss_rr_rrr(t_opcomm *opnode)
{
	if ((!(ft_strcmp(opnode->op, "sa")) && \
		!(ft_strcmp(opnode->next->op, "sb"))) || (!(ft_strcmp(opnode->op, \
		"sb")) && !(ft_strcmp(opnode->next->op, "sa"))))
	{
		opnode->op = ft_strdup("ss");
		delete_opnode_next(opnode);
	}
	else if ((!(ft_strcmp(opnode->op, "ra")) && \
			!(ft_strcmp(opnode->next->op, "rb"))) || (!(ft_strcmp(opnode->op, \
			"rb")) && !(ft_strcmp(opnode->next->op, "ra"))))
	{
		opnode->op = ft_strdup("rr");
		delete_opnode_next(opnode);
	}
	else if ((!(ft_strcmp(opnode->op, "rra")) && \
			!(ft_strcmp(opnode->next->op, "rrb"))) || (!(ft_strcmp(opnode->op, \
			"rrb")) && !(ft_strcmp(opnode->next->op, "rra"))))
	{
		opnode->op = ft_strdup("rrr");
		delete_opnode_next(opnode);
	}
}

void	opcommlst_shorten(t_opcomm *opcomm_list)
{
	t_opcomm	*opnode;

	opnode = opcomm_list->next;
	while (opnode != NULL)
	{
		if (opnode->next != NULL)
			ss_rr_rrr(opnode);
		opnode = opnode->next;
	}
}
