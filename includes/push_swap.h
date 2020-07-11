/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:29:37 by lelida            #+#    #+#             */
/*   Updated: 2020/07/09 13:29:40 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define OK				"\033[32;1mOK\033[00m"
# define KO				"\033[31;1mKO\033[00m"

# define OPT_V			(1 << 0)

# define A				(0)
# define B				(1)

# define SIZE			(50000)

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}					t_node;

typedef struct		s_linklist
{
	t_node			*head;
	t_node			*tail;
	int				size;
	char			letter;
}					t_linklist;

typedef struct		s_stack
{
	int				opt;
	int				fd;
	int				print;
	int				push[2][SIZE];
	int				num_a;
	int				num_b;
	int				count;
	t_linklist		*stack[2];
}					t_stack;

int					init_stack(t_stack *stack, char *av[]);
char				**get_arg(t_stack *stack, char *av[]);
t_linklist			*creat_linkedlist(char stack);
int					check_stack(char **str);
void				free_stack(t_stack *stack);
void				free_str(char **str);
int					get_median(t_stack *stack, int stk, int num);
int					is_substack(t_stack *stack, int med, int s);
int					issort(t_linklist *stack);
void				print_error(void);
void				print_operation(t_stack *stack, const char *str, \
									const char let);
void				print_stack(t_node *src, t_node *dst, char *opt, \
								t_stack *st);
void				sort_stack(t_stack *stack);
void				mini_sort(t_linklist *lst, t_stack *stack);
void				quick_sort(t_stack *stack);
void				merger_stack(t_stack *stack, int med);
void				split_stack(t_stack *stack, int med);
void				rotate(t_linklist *lst, t_stack *stack);
void				revrotate(t_linklist *lst, t_stack *stack);
void				swap(t_linklist *lst, t_stack *stack);
void				push(t_linklist *src, t_linklist *dst, t_stack *stack);
void				doub_opt(t_stack *stack, char *op, void (*f)(t_linklist *,\
							t_stack *));
void				ps_operations(char *op, t_linklist *src, t_stack *st);

#endif
