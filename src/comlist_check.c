/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comlist_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:17:36 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 13:55:22 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	delete_opnode_next(t_opcomm *opnode)
{
	t_opcomm	*tmp;

	tmp = opnode->next;
	opnode->next = tmp->next;
	free(tmp);
}

void	ss_rr_rrr(t_opcomm *opnode)
{
	if ((!(strcmp(opnode->op, "sa")) && !(strcmp(opnode->next->op, "sb"))) || \
		(!(strcmp(opnode->op, "sb")) && !(strcmp(opnode->next->op, "sa"))))
	{
		opnode->op = strdup("ss");
		delete_opnode_next(opnode);
	}
	else if ((!(strcmp(opnode->op, "ra")) && !(strcmp(opnode->next->op, "rb"))) \
		|| (!(strcmp(opnode->op, "rb")) && !(strcmp(opnode->next->op, "ra"))))
	{
		opnode->op = strdup("rr");
		delete_opnode_next(opnode);
	}
	else if ((!(strcmp(opnode->op, "rra")) && \
			!(strcmp(opnode->next->op, "rrb"))) || (!(strcmp(opnode->op, \
			"rrb")) && !(strcmp(opnode->next->op, "rra"))))
	{
		opnode->op = strdup("rrr");
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
