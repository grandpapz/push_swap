#include "./includes/push_swap.h"

int main(int ac, char **av)
{
    t_ms    *ms;
    
    if (ac != 2)
    {
        ft_printf("Usage: ./push_swap [integer array]\n");
        exit (0);
    }
    av++;
    ac--;
    ms = (t_ms *)malloc(sizeof(t_ms));
    if (ac == 1)
        av = arg_splt(&ac, &av);
    init_stacks(ms, ac);
    create_stack(ac, av, ms);
    if (ms->a->len <= 7)
        small_stack_sort(ms);
    else
        devide_stack(ms);
    free_ms(ms);
    return (0);
}