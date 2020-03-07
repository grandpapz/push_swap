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
    printf("A stack elements: ");
    for (i = 0; i <= ms->a->len; i++)
        printf("%d ", ms->a->stack[i]);
    printf("\nB stack elements: ");
    for (i = 0; i <= ms->b->len; i++)
        printf("%d ", ms->b->stack[i]);
    printf("\n Stack max: %d", ms->a->max);
    printf("\n Stack min: %d", ms->a->min);
    printf("\n Total elements in stack: %d", ms->total);
    free(ms);
    return (0);
}