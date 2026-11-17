/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:59:54 by bpancar           #+#    #+#             */
/*   Updated: 2025/04/14 19:02:24 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	errors(char *c)
{
	(void)c;
	write(2, "Error\n", 6);
	exit(1);
}

void	free_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	duplicate_check(t_main *s)
{
	int		temp;
	t_list	*tmp;
	t_list	*tmp1;
	int		i;

	tmp1 = s->a;
	tmp = s->a;
	temp = tmp1->content;
	while (tmp1)
	{
		i = 0;
		while (tmp)
		{
			if (temp == tmp->content)
				i++;
			tmp = tmp->next;
		}
		if (i > 1)
			return (0);
		tmp = tmp1;
		temp = tmp1->content;
		tmp1 = tmp1->next;
	}
	return (1);
}

void	get_min_and_max_a(t_main *s)
{
	t_list	*temp_a;

	temp_a = s->a;

	s->min_a = temp_a->content;
	s->max_a = temp_a->content;
	while (temp_a)
	{
		if (temp_a->content < s->min_a && temp_a->content)
			s->min_a = temp_a->content;
		if (temp_a->content > s->max_a && temp_a->content)
			s->max_a = temp_a->content;
		temp_a = temp_a->next;
	}
}

void	get_min_and_max_b(t_main *s)
{
	t_list	*temp_b;

	temp_b = s->b;

	if (!s->min_b)
		s->min_b = s->b->content;
	if (!s->max_b)
		s->max_b = s->b->content;
	while (temp_b)
	{
		if (temp_b->content < s->min_b && temp_b->content)
			s->min_b = temp_b->content;
		if (temp_b->content > s->max_b && temp_b->content)
			s->max_b = temp_b->content;
		temp_b = temp_b->next;
	}
}

int	distance_a(t_main *s)
{
	t_list	*temp;
	int		i;

	temp = s->a;
	i = -1;
	s->min_a = 0;
	get_min_and_max_a(s);
	while (temp)
	{
		i++;
		if (temp->content == s->min_a)
			return i;
		temp = temp->next;
	}
	return -1;
}

int	distance_b(t_main *s)
{
	t_list	*temp;
	int		i;

	temp = s->b;
	i = 0;
	s->max_b = 0;
	s->min_b = 0;
	get_min_and_max_b(s);
	while (temp)
	{
		if (temp->content == s->min_b)
			return i;
		i++;
		temp = temp->next;
	}
	return -1;
}

void	get_args(t_main *s, char **temp)
{
	int	i;

	i = 0;
	s->a = ft_lstnew(ft_atoi(temp[0]));
	if (!s->a)
		return (free_array(temp), s_free(s), errors("alloc error"));
	while (temp[++i])
		ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(temp[i])));
	s->a_lenght = ft_lstsize(s->a);
	free_array(temp);
	if (!duplicate_check(s))
		return (s_free(s), errors("Error"));
}

void	join_split_and_check(t_main *s, char *av[], int flag)
{
	int		i;
	char	**temp;
	char	*full;
	char	*tmp;

	full = ft_strdup(av[1]);
	if (!*full)
		return (free(full), free(s), errors("Error"));
	if (flag)
	{
		i = 1;
		while (av[++i])
		{
			tmp = full;
			full = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = full;
			full = ft_strjoin(tmp, av[i]);
			free(tmp);
		}
	}
	temp = ft_split(full, ' ');
	free(full);
	if (!temp || !*temp)
		return (free_array(temp), free(s), errors("Error"));
	i = -1;
	while (temp[++i])
	{
		if (ft_isdigit(temp[i]) != 1 || !ft_intrange(temp[i]))
			return (free_array(temp), free(s), errors("Error"));
	}
	get_args(s, temp);
}

int	sorted_check(t_main *s)
{
	t_list	*temp;

	temp = s->a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	absolute_value(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
