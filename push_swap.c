#include "./includes/push_swap.h"
//  Split arguments by 'space'
char    **arg_splt(int *ac, char ***av)
{
    char **str;

    str = ft_strsplit((*av)[0], ' ');
    (*ac) = 0;
    while (str && str[*ac])
        (*ac)++;
    if (*ac == 0)
    {
        ft_printf("Error\n");
        exit(1);
    }
    return (str);
}


int main(int ac, char **av)
{
    int i;
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
    // printf("Stack A [TOP] < ---- [DNO]: ");
    // for (i = ms->a->len - 1; i >= 0; i--)
    //     printf("%d ", ms->a->stack[i]);
    // printf("\nStack B [TOP] < ---- [DNO]: ");
    // for (i = ms->b->len - 1; i >= 0; i--)
    //     printf("%d ", ms->b->stack[i]);
    free_ms(ms);
    return (0);
}