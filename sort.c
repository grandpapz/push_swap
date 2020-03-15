#include "./includes/push_swap.h"

void mini_sort(t_ms *ms, t_stack *stack, int part)
{
    if (part == 2)
        if (!is_sorted(ms->a, 2))
            swap(ms, 'a');
    if (part == 3)
        sort_three(ms, ms->a, 'a');
}

void less_three_sort(t_ms *ms, t_stack *stack, char c)
{
    if (is_sorted(stack, stack->len))
        return;
    if (stack->len <= 3)
        mini_sort(ms, ms->a, ms->a->len);
    // else
    //     split_short();
}

int is_sorted(t_stack *stack, int len)
{
    int i;
    int max;

    i = stack->len - len;
    max = stack->stack[i];
    while (i < stack->len)
    {
        if (stack->stack[i] > max)
            return (0);
        max = stack->stack[i];
        i++;
    }
    return (1);
}

void small_stack_sort(t_ms *ms)
{
    if (is_sorted(ms->a, ms->a->len))
        return;

if (ms->a->len <= 3)
    less_three_sort(ms, ms->a, 'a');
}