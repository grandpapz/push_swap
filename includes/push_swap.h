#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// Define struct 4 stack
typedef struct  s_stack
{
    int     *stack;
    int     len;
    int     max;
    int     min;
}              t_stack;

// Define Main Struct
typedef struct  s_ms
{
    int     min;
    int     max;
    int     total;
    t_stack *a;
    t_stack *b;
}               t_ms;

// Input reading fucntions
char        **arg_splt(int *ac, char ***av);
int         is_sign(char c);
int         validator(t_ms *ms, char *str, int i);
int         main(int ac, char **av);
void        init_stacks(t_ms *ms, int ac);
void        find_min_max(t_stack *array, int range);
void        create_stack(int ac, char **av, t_ms *ms);
void        free_ms(t_ms *ms);

//  Operations
void        push(t_stack *from, t_stack *to, char c);
void        ss(t_ms *ms);
void        swap(t_ms *ms, char c);
void        rotate(t_stack *array, char c);
void        revrot(t_stack *array, char c);

#endif 