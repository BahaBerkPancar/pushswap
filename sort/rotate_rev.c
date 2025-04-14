
#include "../push_swap.h"

void rotate_a(t_list **a)
{
	t_list *first;
	t_list *last;

	if (!a || !*a || !(*a)->next)
		return;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
}

void rotate_b(t_list **b)
{
	t_list *first;
	t_list *last;

	if (!b || !*b || !(*b)->next)
		return;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
}

void rotate(t_main *s, char c)
{
	if (c == 'r')
		ft_printf("%s", "rr\n");
	if (c == 'a')
		ft_printf("%s", "ra\n");
	if (c == 'b')
		ft_printf("%s", "rb\n");
	if ((c == 'a' || c == 'r') && s->a)
		rotate_a(&s->a);
	if ((c == 'b' || c == 'r') && s->b)
		rotate_b(&s->b);
}

void rev_rotate_b(t_list **b)
{
	t_list *prev;
	t_list *last;

	prev = NULL;
	last = *b;
	if (!b || !*b || !(*b)->next)
		return;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

void rev_rotate_a(t_list **a)
{
	t_list *prev;
	t_list *last;

	prev = NULL;
	last = *a;
	if (!a || !*a || !(*a)->next)
		return;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void reverse_rotate(t_main *s, char c)
{
	if (c == 'r')
		ft_printf("%s", "rrr\n");
	if (c == 'a')
		ft_printf("%s", "rra\n");
	if (c == 'b')
		ft_printf("%s", "rrb\n");
	if ((c == 'a' || c == 'r') && s->a)
		rev_rotate_a(&s->a);
	if ((c == 'b' || c == 'r') && s->b)
		rev_rotate_b(&s->b);
}