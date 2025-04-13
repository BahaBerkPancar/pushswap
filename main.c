#include "push_swap.h"

void first_step(int ac, char *av[], t_main *s)
{
	if (ac < 2)
		exit(0);
	if (ac == 2)
		join_split_and_check(s, av, 0);
	else
		join_split_and_check(s, av, 1);
	s->count = ft_lstsize(s->a);
}

void second_step(t_main *s)
{
	if(s->count < 4)
		sort_a(s);
	else
		sort(s);
	// printf("%d", sorted_check(s));
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
	// ft_lstprint(s->a);
	// ft_lstprint(s->b);
}
