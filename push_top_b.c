#include "./includes/push_swap.h"

static int  count_push_sum(t_ms *ms, int part, int mid)
{
    int counter;
    int i;

    counter = 0;
    i = ms->b->len - part;
    while (i < ms->b->len)
    {
        if (ms->b->stack[i] > mid)
            counter++;
        i++;
    }
    return (counter);
}

static void push_back(t_ms *ms, int pb)
{
    int x;

    x = ms->b->len - pb;
    if (pb > x)
    {
        while (x > 0)
        {
            rotate(ms->b, 'b');
            x--;
        }
    }
    else
    {
        while (pb > 0)
        {
            revrot(ms->b, 'b');
            pb--;
        }
    }
    if (ms->b->stack[ms->b->len - ms->b->len] > 
        ms->b->stack[ms->b->len - 1])
        revrot(ms->b, 'b');
}

int         find_mid(int min, int max, int range)
{
    int mid;

    mid = ((min + max) / 2);
    if (range == 4)
        mid = min + 1;
    if (mid > max || mid < min)
        mid = ((min + max) / 2);
    return (mid);
}

int         push_top_b(t_ms *ms, int part)
{
    int mid;
    int p;
    int len;
    int pb;

    find_min_max(ms->b, part);
    mid = find_mid(ms->b->min, ms->b->max, part);
    len = count_push_sum(ms, part, mid);
    p = len;
    pb = 0;
    while (len > 0)
    {
        if (ms->b->stack[ms->b->len - 1] > mid)
        {
            push(ms->b, ms->a, 'a');
            len--;
        }
        else
        {
            rotate(ms->b, 'b');
            pb++;
        }
    }
    push_back(ms, pb);
    return (p);
}