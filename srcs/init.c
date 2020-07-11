/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:30:18 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:30:21 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				free_stack(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (i < 2)
	{
		tmp = stack->stack[i]->head;
		while (tmp)
		{
			stack->stack[i]->head = stack->stack[i]->head->next;
			free(tmp);
			tmp = stack->stack[i]->head;
		}
		i++;
	}
	free(stack->stack[A]);
	free(stack->stack[B]);
}

static void			ft_push(t_linklist *list, int data)
{
	t_node *tmp;

	if (!(tmp = (t_node*)malloc(sizeof(t_node))))
		exit(1);
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (!list->head)
		list->head = tmp;
	list->size += 1;
}

t_linklist			*creat_linkedlist(char stack)
{
	t_linklist *tmp;

	if (!(tmp = (t_linklist*)malloc(sizeof(t_linklist))))
		exit(1);
	tmp->size = 0;
	tmp->letter = stack;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

static void			creat_stack(t_stack *stack, char **str)
{
	stack->stack[0] = creat_linkedlist('a');
	stack->stack[1] = creat_linkedlist('b');
	while (*str)
	{
		ft_push(stack->stack[0], ft_atoi(*str));
		str += 1;
	}
	stack->num_a = 0;
	stack->num_b = 0;
	ft_bzero(stack->push[A], SIZE);
	ft_bzero(stack->push[B], SIZE);
	stack->push[A][0] = stack->stack[A]->size;
}

int					init_stack(t_stack *stack, char *av[])
{
	char	**str;
	int		ret;

	stack->opt = 0;
	str = get_arg(stack, av);
	if (!str[0])
	{
		free_str(str);
		print_error();
	}
	if ((ret = check_stack(str)))
	{
		free_str(str);
		return (ret);
	}
	creat_stack(stack, str);
	free_str(str);
	return (ret);
}
