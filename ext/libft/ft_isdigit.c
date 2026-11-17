/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:13:15 by bpancar           #+#    #+#             */
/*   Updated: 2025/04/14 18:56:03 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '+' || str[i] == '-' || !str[i])
			return (0);
	}
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_intrange(char *str)
{
	long long	n;
	int			neg;
	int			i;

	neg = (*str == '-');
	i = (*str == '-' || *str == '+');
	n = 0;
	while (str[i])
	{
		n = n * 10 + (str[i++] - '0');
		if (n > 2147483648LL)
			return (0);
	}
	if (neg)
		return (n <= 2147483648LL);
	return (n <= 2147483647LL);
}
