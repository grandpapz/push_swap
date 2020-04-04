#include "./includes/push_swap.h"

static int  count_sorted(t_ms *ms, int part)
{
    find_min_max(ms->a, part);
    while (part > 0 && ms->a->stack[ms->a->len - ms->a->len] == ms->a->min)
        part--;
    return (part);
}

static void push_part(t_ms *ms, int part)
{
    while (part-- > 0)
        push(ms->a, ms->b, 'b');
}

void        part_sort_a(t_ms *ms, int part)
{
    int c_part;
    int x;

    c_part = 0;
    x = 0;
    while (part > 3)
    {
        if (is_rev_sorted(ms->a, part))
        {
            push_part(ms, part);
            part = ret_sorted_b(ms, part);
            break ;
        }
        part = count_sorted(ms, part);
        // x = push_top(ms, part);
        part -= x;
        c_part += x;
    }
    mini_sort(ms, part);
    if (part > 3)
        part_sort_b(ms, c_part);
    else
        mini_sort_b(ms, c_part);
}