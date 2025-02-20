#include "push_swap.h"

void first_step(int ac, char *av[], t_main *s)
{
	if (ac < 2)
		exit(0);
	s->count = ac - 1;
	if (ac == 2)
		get_args(s, av, 0);
	else
		get_args(s, av, 1);

	// rotate(s, 'a');
	// ft_lstprint(s->a);
	// swap(s, 'a');
	// ft_lstprint(s->a);
	// reverse_rotate(s, 'a');
	// ft_lstprint(s->a);
	// push(s, 'b');
	// ft_lstprint(s->a);
	// ft_lstprint(s->b);
	// push(s, 'b');
	// ft_lstprint(s->a);
	// ft_lstprint(s->b);
	// push(s, 'a');
	// ft_lstprint(s->a);
	// ft_lstprint(s->b);
}
void second_step(t_main *s)
{
	if(s->count == 2)
		two_ints(s, '2');
	if(s->count == 3)
		two_ints(s, '3');
}
int main(int ac, char *av[])
{
	t_main *s;

	s = NULL;
	s = malloc(sizeof(t_main));
	if (!s)
		exit(0);
	first_step(ac, av, s);
	second_step(s);
	ft_lstprint(s->a);
}
