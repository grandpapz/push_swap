#include "./includes/push_swap.h"
static  int do_op(t_ms *ms, char *op)
{
    
}

static void read_op(t_ms *ms)
{
    char *op;

    while (get_next_line(0, &op) > 0)
    {
        if (!op || ft_strcmp(op, "\n") == 0)
            break ;
        if (do_op(ms, op))
        {
            ft_printf("Error\n");
            free_ms(ms);
            free(op);
            exit(1);
        }
        free(op);
        op = NULL;
    }
    free(op);
}

int main(int ac, char **av)
{
    t_ms *ms;

    if (ac == 1)
        exit (0);
    if (ac > 2)
    {
        ft_printf("usage: ./checker ['integer stack']\n");
        exit (0);
    }
    av++;
    ac--;
    ms = (t_ms *)malloc(sizeof(t_ms));
    if (ac == 1)
        av = arg_splt(&ac, &av);
    init_stacks(ms, ac);
    create_stack(ac, av, ms);
    if (!(is_sorted(ms->a, ms->total)))
        read_op(ms);
    if (is_sorted(ms->a, ms->total))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    free_ms(ms);
    return (0);
}