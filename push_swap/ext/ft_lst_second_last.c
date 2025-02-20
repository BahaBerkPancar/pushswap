#include "../push_swap.h"

t_list	*ft_lst_second_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}