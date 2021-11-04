/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:21:17 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/03 16:25:22 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

t_node_type	*delete_node(t_node_type *node)
{
	t_node_type	*prev;

	prev = node->prev;
	node->next->prev = prev;
	prev->next = node->next;
	free(node);
	node = NULL;
	return (prev->next);
}

t_node_type	*search_tail(t_node_type *head)
{
	t_node_type		*node;

	node = head;
	while (node->next != head)
	{
		node = node->next;
	}
	return (node);
}

t_node_type	*search_node(t_node_type *head, int num)
{
	t_node_type		*node;

	node = head;
	while (node->next != head)
	{
		if (node->value == num)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	add_tail(t_node_type *head, int num)
{
	t_node_type	*node;
	t_node_type *tail;

	tail = search_tail(head);
	node = malloc(sizeof(t_node_type));
	if (!node)
		puts_errmsg_exit();
	node->value = num;
	node->next = head;
	node->prev = tail;
	tail->next = node;
	//headのprevが繋がっていなかった。必要だと思うんだけど。。
	head->prev = node;
}

void	add_beginning(t_node_type *head, int num)
{
	t_node_type	*node;
	t_node_type *begin;

	begin = head->next;
	node = malloc(sizeof(t_node_type));
	if (!node)
		puts_errmsg_exit();
	node->value = num;
	node->prev	= head;
	node->next = begin;
	begin->prev = node;
	head->next = node;
}
