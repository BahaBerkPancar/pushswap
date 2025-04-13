/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MKRAForce <MKRAForce@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:56:53 by bpancar           #+#    #+#             */
/*   Updated: 2025/02/23 22:52:21 by MKRAForce        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((len > ft_strlen(s + start)))
		len = ft_strlen(s + start);
	src = malloc(sizeof(char) * (len + 1));
	if (!src)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			src[j] = s[i];
			j++;
		}
		i++;
	}
	src[j] = '\0';
	return (src);
}