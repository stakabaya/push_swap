# include "../include/push_swap.h"
# include <push_swap.h>

//Need to be modyfied/////////////////////////////////////////////////////////////////////////////////

void	print_list(t_node_type *head)
{
	t_node_type	*node;

	node = head->next;
	while (node != head)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

void	print_op_list(t_opcomm *head)
{
	t_opcomm	*node;

	node = head->next;
	while (node != NULL)
	{
		ft_putendl_fd(node->op, 1);
		node = node->next;
	}
}

//error program/////////////////////////////////////////////////////////////////////////////////

void	clear_stack_list(t_node_type *head)
{
	t_node_type	*node;
	t_node_type *tmp;

	if (head->next != head)
	{
		node = head->next;
		while (node->next != head)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		free(node);
		node = NULL;
	}
}

void	clear_opcomm_list(t_opcomm *head)
{
	t_opcomm	*node;
	t_opcomm	*tmp;

	if (head->next != NULL)
	{
		node = head->next;
		while (node->next != NULL)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
		free(node);
		node = NULL;
	}
}

void end_program(t_opcomm *operations, t_node_type *a_stack, t_node_type *b_stack)
{
    clear_opcomm_list(operations);
   	clear_stack_list(a_stack);
	clear_stack_list(b_stack);
    exit(EXIT_SUCCESS);
}

//Common list oparation/////////////////////////////////////////////////////////////////////////////////

//削除するノードのprevとnextをそれぞれ前後のノード同士に繋ぐ


t_opcomm	*opsearch_tail(t_opcomm *head)
{
	t_opcomm		*node;

	node = head;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}


//List operations for opcommand/////////////////////////////////////////////////////////////////////////////

int	op_add_tail(t_opcomm *head, char *command)
{
	t_opcomm	*node;
	t_opcomm 	*tail;

	tail = opsearch_tail(head);
	node = malloc(sizeof(t_opcomm));
	if (node == NULL)
		puts_errmsg_exit();
	node->op = strdup(command);
	if (node->op == NULL)
		puts_errmsg_exit();
	node->next = NULL;
	tail->next = node;
	return (1);
}

//List operations for stack/////////////////////////////////////////////////////////////////////////////////


int	is_str_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
	{
		if(!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

void	clear_words(char **words)
{
	int	idx;
	char	**tmp;

	idx = 0;
	tmp = words;
	while (words[idx] != NULL)
		free(words[idx++]);
	if (tmp != NULL)
		free(tmp);
}



//Oparation commands/////////////////////////////////////////////////////////////////////////////////

void	rotate(t_node_type *head, t_opcomm *oplst, char *com)
{
	add_tail(head, head->next->value);
	delete_node(head->next);
	if (!strcmp(com, "ra"))
		op_add_tail(oplst, "ra");
	else if (!strcmp(com, "rb"))
		op_add_tail(oplst, "rb");
}

void	rotate_rev(t_node_type *head, t_opcomm *oplst, char *com)
{
	add_beginning(head, head->prev->value);
	delete_node(head->prev);
	if (!strcmp(com, "rra"))
		op_add_tail(oplst, "rra");
	else if (!strcmp(com, "rrb"))
		op_add_tail(oplst, "rrb");
}

void	push_a(t_node_type *a_list, t_node_type *b_list, t_opcomm *oplst)
{
	t_node_type	*a_head;
	t_node_type	*b_head;

	a_head = a_list->next;
	b_head = b_list->next;
	add_beginning(a_list, b_head->value);
	delete_node(b_head);
	op_add_tail(oplst, "pa");
}

void	push_b(t_node_type *a_list, t_node_type *b_list, t_opcomm *oplst)
{
	t_node_type	*a_head;
	t_node_type	*b_head;

	a_head = a_list->next;
	b_head = b_list->next;
	add_beginning(b_list, a_head->value);
	delete_node(a_head);
	op_add_tail(oplst, "pb");
}

void	swap_node(t_node_type *a, t_node_type *b)
{
	t_node_type	*tmp;

	b->prev->next = a;
	a->prev->next = b;
	tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;

	a->next->prev = b;
	b->next->prev = a;
	tmp = a->next;
	a->next = b->next;
	b->next = tmp;
}

void	swap_a(t_node_type *list, t_opcomm *oplst)
{
	t_node_type	*a;
	t_node_type	*b;

	a = list->next;
	b = a->next;
	swap_node(a, b);
	op_add_tail(oplst, "sa");
}

void	swap_b(t_node_type *list, t_opcomm *oplst)
{
	t_node_type	*a;
	t_node_type	*b;

	a = list->next;
	b = a->next;
	swap_node(a, b);
	op_add_tail(oplst, "sb");
}

//Util/////////////////////////////////////////////////////////////////////////////////


void	search_min_half(int *min, t_node_type *list, int *half, int *count)
{
	t_node_type		*node;


	node = list->next;
	*min = node->value;
	// node = node->next;
	*half = 0;
	*count = 0;
	while (node != list)
	{
		if (*min > node->value)
			*min = node->value;
		*half += (int)node->value;
		node = node->next;
		*count = *count + 1;
	}
	if (*count == 0)
		return ;
	*half = *half / *count;
	// if (*(half % 2) == 1)
}

void	search_min_half2(int *min, t_node_type *chunklst, t_node_type *list, int *half, int *count)
{
	t_node_type		*node;


	node = list->next;
	*min = node->value;
	// node = node->next;
	*half = 0;
	*count = 0;
	while (node != list)
	{
		if (*min > node->value)
			*min = node->value;
		*half += (int)node->value;
		*count = *count + 1;
		if (chunklst->next != chunklst)
			if (node->value == chunklst->next->value)
				break;
		node = node->next;
		
	}
	if (*count == 0)
		return ;
	*half = *half / *count;
	// if (*(half % 2) == 1)
}

//Decent Order for under 6 args//////////////////////////////////////////////////////////////////






//Util For over 6 Args//////////////////////////////////////////////////////////////////

void	div_low_half(t_node_type *source, t_node_type *dest, int *count, t_opcomm *oplst)
{
	int			min;
	int			half;
	int			i;
	
	search_min_half(&min, source, &half, count);
	i = *count;
	while (i)
	{
		if (source->next->value <= half)
		{
			push_b(source, dest, oplst);
		}
		else
			rotate(source, oplst, "ra");
		i--;
	}
}

void	move_chunk(t_node_type *source, t_node_type *dest, int *count, t_node_type *chunklst, t_opcomm *oplst)
{
	int			min;
	int			half;

	search_min_half(&min, source, &half, count);
	while (source->next->value != min)
	{
		push_b(source, dest, oplst);
		if (chunklst->next != chunklst)
		{
			if (dest->next->value == chunklst->next->value)
			{
				delete_node(chunklst->next);	
				break ;
			}
		}
	}
}

void	div_up_half(t_node_type *source, t_node_type *dest, int *count, t_node_type *chunklst, t_opcomm *oplst)
{
	int			min;
	int			half;
	int			flag;
	int			i;
	
	flag = 0;
	search_min_half(&min, source, &half, count);
	i = *count;	
	while (i)
	{
		if (source->next->value > half)
		{
			push_a(dest, source, oplst);
			(*count)--;
			if (flag == 0)
			{
				add_beginning(chunklst, dest->next->value);
				flag = 1;
			}
		}
		else
			rotate(source, oplst, "rb");
		i--;
	}
}


//
//1. aの下半分をbにする
//2. bが３つ以下である場合は並び替える
//3. bが3つ以下になるまで上半分をaに送る
//4. bを並び替えてaに送って最後尾に送る。
//⇨現状、bからaに送るときに何回も分けて送っているのに、結局aから再度全部合せた下半分をbに送ってしまっている
//bからaに送るときの半分にするチャンクを覚えておいて、利用するとほんとのquick sortになる。


void	init_chunk(t_node_type *chunk_list)
{
	chunk_list->next = chunk_list;
	chunk_list->prev = chunk_list;
	chunk_list->value = 0;

}
void	more_args(t_node_type *a, t_node_type *b, t_opcomm *oplst)
{
	int			min;
	int			half;
	int			count;
	t_node_type chunk_list;

	init_chunk(&chunk_list);
	div_low_half(a, b, &count, oplst);		
	while (1)
	{
		search_min_half(&min, b, &half, &count);
		while (count > 3)
			div_up_half(b, a, &count, &chunk_list, oplst);
		three_args(b, oplst, "b");
		while (b->next != b)
		{
			push_a(a, b, oplst);
			rotate(a, oplst, "ra");
		}
		if (is_sorted(a))
			break ;
		move_chunk(a, b, &count, &chunk_list, oplst);
	}
}


//100 = 7208 times
#define AGNUM 10

void	delete_opnode_next(t_opcomm *opnode)
{
	t_opcomm	*tmp;

	tmp = opnode->next;
	opnode->next = tmp->next;
	free(tmp);
}

void	ss_rr_rrr(t_opcomm *opnode)
{
	if ((!(strcmp(opnode->op, "sa")) && !(strcmp(opnode->next->op, "sb"))) ||
		(!(strcmp(opnode->op, "sb")) && !(strcmp(opnode->next->op, "sa"))))
	{
		opnode->op = strdup("ss");
		delete_opnode_next(opnode);
	}
	else if ((!(strcmp(opnode->op, "ra")) && !(strcmp(opnode->next->op, "rb"))) ||
		(!(strcmp(opnode->op, "rb")) && !(strcmp(opnode->next->op, "ra"))))
	{
		opnode->op = strdup("rr");
		delete_opnode_next(opnode);
	}
	else if ((!(strcmp(opnode->op, "rra")) && !(strcmp(opnode->next->op, "rrb"))) ||
		(!(strcmp(opnode->op, "rrb")) && !(strcmp(opnode->next->op, "rra"))))
	{
		opnode->op = strdup("rrr");
		delete_opnode_next(opnode);
	}
}

void	opcommlst_shorten(t_opcomm *opcomm_list)
{
	t_opcomm *opnode;
	
	opnode = opcomm_list->next;
	while (opnode != NULL)
	{
		if (opnode->next != NULL)
		{
			ss_rr_rrr(opnode);
		}
		opnode = opnode->next;
	}
}







void	make_list(t_node_type *head, char **agv)
{
	long	num;
	int		errno;

	errno = 0;
	while (*agv != NULL)
	{
		catch_error(is_str_num(*agv));
		num = ft_atoi(*agv);
		if (errno != 0)
			puts_errmsg_exit();
		add_tail(head, num);
		agv++;
	}
}


void	listinit(t_node_type *ahead, t_node_type *bhead, t_opcomm *ohead)
{
	ahead->next = ahead;
	ahead->prev = ahead;
	ahead->value = 0;
	bhead->next = bhead;
	bhead->prev = bhead;
	bhead->value = 0;
	ohead->next = NULL;
	ohead->op = NULL;
}


int		main(int argc, char **argv)
{
	t_node_type	a_list;
	t_node_type	b_list;
	t_opcomm	opcomm_list;

	argv++;
	listinit(&a_list, &b_list, &opcomm_list);
	if (--argc > 1000 ||argc < 1)
		puts_errmsg_exit();
	make_list(&a_list, argv);
	sortlst(argc, &a_list, &b_list, &opcomm_list);
	opcommlst_shorten(&opcomm_list);
	print_op_list(&opcomm_list);
	end_program(&opcomm_list, &a_list, &b_list);
	system("leaks a.out");
	return (0);
}
