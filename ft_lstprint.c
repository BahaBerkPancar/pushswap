#include "../push_swap.h"

void ft_lstprint(t_list *lst) 
{
    while (lst) {
        printf("%d -> ", lst->content); // İçerik `char *` ise
        lst = lst->next;
    }
    printf("NULL\n");
}
