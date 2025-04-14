#include "../push_swap.h"


void	swap_a(t_list *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
}

void	swap_b(t_list *b)
{
	int	tmp;

	if (!b)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
}

void swap(t_main *s, char c)
{
	if (c == 's')
		ft_printf("%s", "ss\n");
	if (c == 'a')
		ft_printf("%s", "sa\n");
	if (c == 'b')
		ft_printf("%s", "sb\n");
	if ((c == 'a' || c == 's') && s->a && s->a->next)
		swap_a(s->a);
	if ((c == 'b' || c == 's') && s->b && s->b->next)
		swap_b(s->b);
}


void	push_a(t_main *s)
{
	t_list	*tmp;

	if (!s->b)
		return ;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->a;
	s->a = tmp;
	s->a_lenght++;
	s->b_lenght--;
}

void	push_b(t_main *s)
{
	t_list	*tmp;

	if (!s->a)
		return ;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->b;
	s->b = tmp;
	s->a_lenght--;
	s->b_lenght++;
}

void push(t_main *s, char c)
{
	if (c == 'a')
		ft_printf("%s", "pa\n");
	if (c == 'b')
		ft_printf("%s", "pb\n");
	if (c == 'a' && s->a)
		push_a(s);
	if (c == 'b')
		push_b(s);
}
