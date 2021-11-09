/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakabay <stakabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:14:19 by stakabay          #+#    #+#             */
/*   Updated: 2021/11/09 22:11:47 by stakabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_node_type
{
	int						value;
	struct s_node_type		*next;
	struct s_node_type		*prev;
}				t_node_type;

typedef struct s_opcomm
{
	char					*op;
	struct s_opcomm			*next;
}				t_opcomm;

typedef struct s_lists
{
	t_node_type	*a_list;
	t_node_type	*b_list;
	t_opcomm	*opcom_list;
}				t_lists;

int			catch_null(void	*str, t_lists *lists);
int			catch_error(int rt, t_lists *lists);
void		puts_errmsg_exit(void);
void		add_beginning(t_node_type *head, t_lists *lists, int num);
void		add_tail(t_node_type *head, t_lists *lists, int num);
t_node_type	*search_node(t_node_type *head, int num);
t_node_type	*delete_node(t_node_type *node);
void		sortlst(t_lists *lists, int argc);
void		three_args(t_node_type *stack, t_lists *lists, char *com);
void		search_min_max(int *min, int *max, t_node_type *list);
void		case_one(t_lists *lists, char *com);
void		case_two(t_lists *lists, char *com);
void		case_three(t_lists *lists, char *com);
void		case_four(t_lists *lists, char *com);
void		case_five(t_lists *lists, char *com);
int			is_sorted(t_node_type *list);
void		more_args(t_lists *lists);
void		rotate(t_node_type *head, t_lists *lists, char *com);
void		rotate_rev(t_node_type *head, t_lists *lists, char *com);
void		push_a(t_lists *lists);
void		push_b(t_lists *lists);
void		swap_node(t_node_type *a, t_node_type *b);
void		swap_a(t_lists *lists);
void		swap_b(t_lists *lists);
void		end_program(t_lists *lists);
void		div_low_half(t_lists *lists, int *count);
void		move_chunk(t_lists *lists, int *count, t_node_type *chunklst);
void		div_up_half(t_lists *lists, int *count, t_node_type *chunklst);
void		search_min_half(int *min, t_node_type *list, \
							long *half, int *count);
void		opcommlst_shorten(t_opcomm *opcomm_list);
int			op_add_tail(t_lists *lists, char *command);
void		print_op_list(t_opcomm *head);
void		error_end_program(t_lists *lists);
void		clear_stack_list(t_node_type *head);
void		clear_opcomm_list(t_opcomm *head);
t_node_type	*search_tail(t_node_type *head);
void		ft_free_flag(char **ptr, int flag);

#endif