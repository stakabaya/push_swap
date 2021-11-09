/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:38:34 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/09 22:24:35 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <push_swap.h>

// void	print_list(t_node_type *head)
// {
// 	t_node_type	*node;

// 	node = head->next;
// 	while (node != head)
// 	{
// 		ft_putnbr_fd(node->value, 1);
// 		ft_putendl_fd("", 1);
// 		node = node->next;
// 	}
// }

int	is_str_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	add_list(t_lists *lists, int num)
{
	t_node_type	*node;
	t_node_type	*tail;
	t_node_type	*head;

	head = lists->a_list;
	tail = search_tail(head);
	node = malloc(sizeof(t_node_type));
	if (!node)
		return (0);
	node->value = num;
	node->next = head;
	node->prev = tail;
	tail->next = node;
	head->prev = node;
	return (1);
}

void	make_list(t_lists *lists, char **agv, int flag, int argc)
{
	long	num;
	int		errno;
	char	**start;

	start = agv;
	errno = 0;
	while (*agv != NULL)
	{
		catch_error(is_str_num(*agv), lists);
		num = ft_atoi(*agv);
		if (errno != 0 || !add_list(lists, num))
		{
			ft_free_flag(start, flag);
			error_end_program(lists);
		}
		agv++;
	}
	ft_free_flag(start, flag);
	if (argc == 1 || is_sorted(lists->a_list))
		end_program(lists);
}

void	listinit(t_lists *lists, t_node_type *ahead, \
				t_node_type *bhead, t_opcomm *ohead)
{
	lists->a_list = ahead;
	lists->b_list = bhead;
	lists->opcom_list = ohead;
	ahead->next = ahead;
	ahead->prev = ahead;
	ahead->value = 0;
	bhead->next = bhead;
	bhead->prev = bhead;
	bhead->value = 0;
	ohead->next = NULL;
	ohead->op = NULL;
}

int	main(int argc, char **argv)
{
	t_node_type	a_list;
	t_node_type	b_list;
	t_opcomm	opcomm_list;
	t_lists		lists;
	int			flag;

	argv++;
	flag = 0;
	listinit(&lists, &a_list, &b_list, &opcomm_list);
	if (--argc > 1000 || argc == 0)
		error_end_program(&lists);
	if ((argc == 1 && ft_strchr(*argv, ' ') && flag++ == 0))
	{
		argv = ft_split(*argv, ' ');
		if (argv == NULL || *argv == NULL)
			error_end_program(&lists);
		argc = 0;
		while (argv[argc])
			argc++;
	}
	make_list(&lists, argv, flag, argc);
	sortlst(&lists, argc);
	opcommlst_shorten(&opcomm_list);
	print_op_list(&opcomm_list);
	end_program(&lists);
}

// #include <stdio.h>
// void    destructor_leaks(void)__attribute__((destructor));
// void    destructor_leaks(void)
// {
//    system("leaks push_swap");
// }