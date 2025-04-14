#include "../push_swap.h"

static void three_ints(t_main *s, char x, int *i, char c)
{
	if (x == '3')
	{
		if (i[0] < i[1] && i[0] >= i[2] && i[1] > i[2])
			reverse_rotate(s, c);
		else if (i[0] > i[1] && i[0] <= i[2] && i[1] < i[2])
			swap(s, c);
		else if (i[0] > i[1] && i[0] > i[2] && i[1] > i[2])
		{
			rotate(s, c);
			swap(s, c);
		}
		else if (i[0] > i[1] && i[0] >= i[2] && i[1] < i[2])
			rotate(s, c);
		else if (i[0] < i[1] && i[0] <= i[2] && i[1] > i[2])
		{
			reverse_rotate(s, c);
			swap(s, c);
		}
		else if (i[0] > i[1] && i[0] > i[2] && i[1] <= i[2])
			rotate(s, c);
		else if (i[0] <= i[1] && i[0] > i[2] && i[1] > i[2])
			reverse_rotate(s, c);
		free(i);
	}
}

void two_ints(t_main *s, char x, char c)
{
	int *i;
	i = NULL;
	if (x == '2')
	{
		if (s->a->content > s->a->next->content)
			swap(s, c);
	}
	else
	{
		i = malloc(sizeof(int) * 3);
		if (!i)
			return (errors("alloc error"));
		i[0] = s->a->content;
		i[1] = s->a->next->content;
		i[2] = s->a->next->next->content;
		three_ints(s, x, i, c);
	}
}
