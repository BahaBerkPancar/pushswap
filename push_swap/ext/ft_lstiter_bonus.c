/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:13:33 by bpancar           #+#    #+#             */
/*   Updated: 2025/02/08 03:08:20 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	i;

	if (!f)
		return ;
	i = ft_lstsize(lst);
	while (0 < i)
	{
		f(lst->content);
		lst = lst->next;
		i--;
	}
}
