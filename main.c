#include "push_swap.h"

void get_args(t_main *s, char *av[], int flag)
{
	int i;
	char **temp;

	i = 1;
	if(flag == 0)
	{
		temp = NULL;
		i -= 2;
		temp = ft_split(av[1], ' ');
		s->a = ft_lstnew(ft_atoi(temp[0]));
		while(temp[++i])
		{
			ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(temp[i])));
		}
		ft_lstprint(s->a);
	}
	if (flag == 1)
	{	
		s->a = ft_lstnew(ft_atoi(av[1]));
		while(++i <= s->count)
			ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(av[i])));
	}
}
void first_step(int ac, char *av[], t_main *s)
{
	if(ac < 2)
		exit(0);
	s = malloc(sizeof(t_main));
	if(!s)
		exit(0);
	s->count = ac - 1;
	printf("you appear to decide sort %d integers", s->count);
	if(ac == 2)
		get_args(s, av, 0);
	else
		get_args(s, av, 1);
}
int main(int ac, char *av[])
{
	t_main *s;
	s = NULL;
	first_step(ac, av, s);
	
}
