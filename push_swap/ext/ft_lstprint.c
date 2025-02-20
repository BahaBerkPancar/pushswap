#include "../push_swap.h"

void ft_lstprint(t_list *lst) 
{
    while (lst) {
        ft_printf("%d -> ", lst->content); // İçerik `char *` ise
        lst = lst->next;
    }
    ft_printf("NULL\n");
}
