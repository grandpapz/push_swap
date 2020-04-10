#include "./includes/push_swap.h"

int     is_sign(char c)
{
    return (c == '-' || c == '+');
}

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