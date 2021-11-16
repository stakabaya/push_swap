/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:38:34 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/16 12:26:29 by stakabay         ###   ########.fr       */
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

void	make_list(t_lists *lists, char **agv, int flag)
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

char	**expand_arg(int argc, char **argv, int *flag, t_lists *lists)
{
	if (argc == 1 && ft_strchr(*argv, ' '))
	{
		argv = ft_split(*argv, ' ');
		if (argv == NULL || *argv == NULL)
			error_end_program(lists);
		argc = 0;
		while (argv[argc])
			argc++;
		(*flag)++;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_node_type	a_list;
	t_node_type	b_list;
	t_opcomm	opcomm_list;
	t_lists		lists;
	int			flag;

	flag = 0;
	listinit(&lists, &a_list, &b_list, &opcomm_list);
	if (argc == 0)
		return (0);
	if (--argc > 1000)
		error_end_program(&lists);
	argv = expand_arg(argc, ++argv, &flag, &lists);
	make_list(&lists, argv, flag);
	sortlst(&lists, argc);
	opcommlst_shorten(&opcomm_list, &lists);
	print_op_list(&opcomm_list);
	end_program(&lists);
}

// #include <stdio.h>
// void    destructor_leaks(void)__attribute__((destructor));
// void    destructor_leaks(void)
// {
//    system("leaks push_swap");
// }