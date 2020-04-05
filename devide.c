#include "./includes/push_swap.h"
static int  count_push_sum(t_ms *ms, int part, int mid)
{
    int counter;
    int i;

    counter = 0;
    i = ms->a->len - part;
    while (i < ms->a->len)
    {
        if (ms->a->stack[i] < mid)
            counter++;
        i++;
    }
    return (counter);
}  

static void        push_part(t_ms *ms, int part)
{
    while   (part > 0)
    {
        push(ms->a, ms->b, 'b');
        part--;
    }
}

static int         init_push(t_ms *ms, int part)
{
    int mid;
    int len;
    
    if (ms->a->len > 400)
        mid = ((ms->a->min + ms->a->max) / 3);
    else
        mid = ((ms->a->min + ms->a->max) / 2);
    len = count_push_sum(ms, ms->a->len, mid);
    while (len > 0)
    {
        if (ms->a->stack[ms->a->len - 1] < mid)
        {
            push(ms->a, ms->b, 'b');
            part++;
            len--;
        }
        else
            rotate(ms->a, 'a');
    }
    return (part);
}

static void        part_sort(t_ms *ms, int *part, int i)
{
    while (i >= 0)
    {
        if (is_sorted(ms->b, part[i]) && part[i] > 0)
        {
            part[i] = ret_sorted_b(ms, part[i]);
            i--;
        }
        if (part[i] == 1)
            push(ms->b, ms->a, 'a');
        if (part[i] > 1)
            part_sort_b(ms, part[i]);
        i--;
    }
}

void        devide_stack(t_ms *ms)
{
    int *p;
    int i;

    i = 0;
    p = ft_memalloc(ms->total * sizeof(int));
    while (ms->a->len > 3)
    {
        if (is_sorted(ms->a, ms->a->len))
            break ;
        if (is_rev_sorted(ms->a, ms->a->len))
        {
            p[i] = ms->a->len;
            push_part(ms, ms->a->len);
            p[i] = ret_sorted_b(ms, p[i]);
            break ;
        }
        find_min_max(ms->a, ms->a->len);
        p[i] = init_push(ms, 0);
        i++;
    }
    mini_sort(ms, ms->a->len);
    part_sort(ms, p, i);
    free(p);
}