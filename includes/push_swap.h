#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/ft_printf.h"
// #include "../libft/includes/libft.h"
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

char        **arg_splt(int *ac, char ***av);

int         is_sign(char c);
int         validator(t_ms *ms, char *str, int i);
int         main(int ac, char **av);

void        init_stacks(t_ms *ms, int ac);
void        find_min_max(t_stack *array, int range);
void        create_stack(int ac, char **av, t_ms *ms);
void        free_ms(t_ms *ms);

#endif 