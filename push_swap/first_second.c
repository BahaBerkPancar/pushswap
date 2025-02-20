#include "push_swap.h"

void get_args(t_main *s, char *av[], int flag)
{
	int i;
	char **temp;

	i = 0;
	if (flag == 0)
	{
		temp = NULL;
		temp = ft_split(av[1], ' ');
		if (!temp)
			return (free(temp), free(s), errors("split error"));
		s->a = ft_lstnew(ft_atoi(temp[0]));
		if (!s->a)
			return (free(temp), free(s), errors("alloc error"));
		while (temp[++i])
			ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(temp[i])));
		free(temp);
	}
	if (flag == 1)
	{
		i = 1;
		s->a = ft_lstnew(ft_atoi(av[1]));
		if (!s->a)
			return (free(s), errors("alloc error"));
		while (++i <= s->count)
			ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(av[i])));
	}
	s->a_lenght = ft_lstsize(s->a);
	s->b_lenght = ft_lstsize(s->b);
	ft_printf("you appear to decide sort %zu integers\n", s->a_lenght);
	ft_lstprint(s->a);
}

void two_ints(t_main *s, char x)
{
	int *i;
	if (x == '2')
	{
		if (s->a->content > s->a->next->content)
			swap(s, 'a');		
	}
	if (x == '3')
	{
		i = malloc(sizeof(int) * 3);
		if (!i)
			return (errors("alloc error"));
		i[0] = s->a->content;
		i[1] = s->a->next->content;
		i[2] = s->a->next->next->content; 
		if (i[0] < i[1] && i[0] >= i[2] && i[1] > i[2])
			reverse_rotate(s, 'a');
		else if (i[0] > i[1] && i[0] <= i[2] && i[1] < i[2])
			swap(s, 'a');
		else if (i[0] > i[1] && i[0] > i[2] && i[1] > i[2])
		{
			rotate(s, 'a');
			swap(s, 'a');
		}
		else if(i[0] > i[1] && i[0] >= i[2] && i[1] < i[2])
			rotate(s, 'a');
		else if(i[0] < i[1] && i[0] <= i[2] && i[1] > i[2])
		{
			reverse_rotate(s, 'a');
			swap(s, 'a');
		}
		else if(i[0] > i[1] && i[0] > i[2] && i[1] <= i[2])
			rotate(s, 'a');
		else if (i[0] <= i[1] && i[0] > i[2] && i[1] > i[2])
		reverse_rotate(s, 'a');
		free(i);

	}
}
