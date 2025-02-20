#include "push_swap.h"

void swap(t_main *s, char c)
{
	t_list *swap;

	(void)s;
	(void)c;
	(void)swap;
	if (c == 's')
		ft_printf("%s", "ss\n");
	if (c == 'a')
		ft_printf("%s", "sa\n");
	if (c == 'b')
		ft_printf("%s", "sb\n");
	if ((c == 'a' || c == 's') && s->a && s->a->next)
	{
		swap = ft_lstnew(s->a->next->content);
		swap->next = ft_lstnew(s->a->content);
		s->a = s->a->next->next;
		ft_lstadd_front(&s->a, swap->next);
		ft_lstadd_front(&s->a, swap);
	}
	if ((c == 'b' || c == 's') && s->b && s->b->next)
	{
		swap = ft_lstnew(s->b->next->content);
		swap->next = ft_lstnew(s->b->content);
		s->b = s->b->next->next;
		ft_lstadd_front(&s->b, swap->next);
		ft_lstadd_front(&s->b, swap);
	}
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
	{
		ft_lstadd_back(&s->a, ft_lstnew(s->a->content));
		s->a = s->a->next;
	}
	if ((c == 'b' || c == 'r') && s->b)
	{
		ft_lstadd_back(&s->b, ft_lstnew(s->b->content));
		s->b = s->b->next;
	}
}
void reverse_rotate(t_main *s, char c)
{
	t_list *temp;
	t_list *last;

	if (c == 'r')
		ft_printf("%s", "rrr\n");
	if (c == 'a')
		ft_printf("%s", "rra\n");
	if (c == 'b')
		ft_printf("%s", "rrb\n");
	if ((c == 'a' || c == 'r') && s->a)
	{
		temp = ft_lst_second_last(s->a);
		last = ft_lstlast(s->a);
		temp->next = NULL;
		ft_lstadd_front(&s->a, last);
	}
	if ((c == 'b' || c == 'r') && s->b)
	{
		temp = ft_lst_second_last(s->b);
		last = ft_lstlast(s->b);
		temp->next = NULL;
		ft_lstadd_front(&s->b, last);
	}
}
void push(t_main *s, char c)
{
	if (c == 'a')
		ft_printf("%s", "pa\n");
	if (c == 'b')
		ft_printf("%s", "pb\n");
	if (c == 'a' && s->a)
	{
		ft_lstadd_front(&s->a, ft_lstnew(s->b->content));
		s->b = s->b->next;
		s->a_lenght++;
		s->b_lenght--;
	}
	if (c == 'b')
	{
		if (!s->b)
			s->b = ft_lstnew(s->a->content);
		else
			ft_lstadd_front(&s->b, ft_lstnew(s->a->content));
		s->a = s->a->next;
		s->a_lenght--;
		s->b_lenght++;
	}
}
