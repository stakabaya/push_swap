/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:26:31 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/09 22:12:19 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <push_swap.h>

void	error_end_program(t_lists *lists)
{
	write(2, "Error\n", 6);
	clear_opcomm_list(lists->opcom_list);
	clear_stack_list(lists->a_list);
	clear_stack_list(lists->b_list);
	exit(EXIT_FAILURE);
}

int	catch_error(int rt, t_lists *lists)
{
	if (rt <= 0)
		error_end_program(lists);
	return (1);
}

int	catch_null(void	*str, t_lists *lists)
{
	printf("-%s-", (char *)str);
	if (str == NULL)
		error_end_program(lists);
	return (1);
}
