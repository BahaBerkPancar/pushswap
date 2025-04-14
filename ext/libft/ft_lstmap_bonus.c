/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:13:37 by bpancar           #+#    #+#             */
/*   Updated: 2025/04/14 18:57:05 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	void	*tc;
	t_list	*final;

	if (!lst)
		return (NULL);
	final = NULL;
	while (lst != NULL)
	{
		tc = f(lst->content);
		if (!tc)
			return (ft_lstclear(&final, del), NULL);
		tmp = ft_lstnew(tc);
		if (!tmp)
			return (del(tc), ft_lstclear(&final, del), NULL);
		ft_lstadd_back(&final, tmp);
		lst = lst->next;
	}
	return (final);
}
