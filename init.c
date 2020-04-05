#include "./includes/push_swap.h"
//  Destructor of main struct.
void        free_ms(t_ms *ms)
{
    free(ms->a->stack);
    free(ms->b->stack);
    free(ms->a);
    free(ms->b);
    free(ms);
    ms = NULL;
}

//Validator for input. OK - return (1), else return (0);
int         validator(t_ms *ms, char *str, int i)
{
    // Check that input is digit or sign, and it in int range.
    if (!ft_isdigit(str[0]) && !is_sign(str[0]))
        return (0);
    if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
        return (0);
    // Check that input have no doubles.
    while (i >= 0 && i <= ms->a->len)
    {
        if (ft_atoi(str) == ms->a->stack[i] && ft_atoi(str) != 0)
            return (0);
        i--;
    }
    return (1);
}

// Initialized stacks, len of stacks == ac. Stack 'b' filled with '0'
void        init_stacks(t_ms *ms, int ac)
{
    ms->a = (t_stack *)malloc(sizeof(t_stack));
    ms->b = (t_stack *)malloc(sizeof(t_stack));
    ms->a->stack = (int *)malloc(sizeof(int) * (ac));
    ms->b->stack = (int *)ft_memalloc(sizeof(int) * (ac));
    ms->b->len = 0;
}

// Find stack's max and min values.
void        find_min_max(t_stack *array, int range)
{
    int i;

    i = array->len - range;
    array->max = INT_MIN;
    array->min = INT_MAX;
    while (i < array->len)
    {
        if (array->stack[i] > array->max)
            array->max = array->stack[i];
        if (array->stack[i] < array->min)
            array->min = array->stack[i];
        i++;
    }
}

//Create stack 'a', fill it with arguments.
void        create_stack(int ac, char **av, t_ms *ms)
{
    int i;
    int top;

    i = 0;
    top = ac - 1;
    while (i < ac)
    {
        if (validator(ms, av[top - i], i))
            ms->a->stack[i] = ft_atoi(av[top - i]);
        else
        {
            free_ms(ms);
            ft_printf("Error\n");
            exit(1);
        }
        i++;
        ms->a->len = i;
        find_min_max(ms->a, ms->a->len);
        ms->max = ms->a->max;
        ms->min = ms->a->min;
        ms->total = i;
    }
}