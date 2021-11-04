/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:26:31 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/04 13:38:32 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	puts_errmsg_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	catch_error(int rt)
{
	if (rt <= 0)
		puts_errmsg_exit();
	return (1);
}

int	catch_null(void	*str)
{
	if (str == NULL)
		puts_errmsg_exit();
	return (1);
}
