#include "../push_swap.h"

// static void sort_b(t_main *s)
// {
// 	if(s->b_lenght == 2)
// 		two_ints(s, '2', 'b');
// 	if(s->b_lenght == 3)
// 		two_ints(s, '3', 'b');
// }

void sort_a(t_main *s)
{
	if(s->a_lenght == 2)
		two_ints(s, '2', 'a');
	if(s->a_lenght == 3)
		two_ints(s, '3', 'a');
}

int get_closest(t_main *s, int content, int closest)
{
	t_list *temp;

	get_min_and_max_a(s);
	get_min_and_max_b(s);
	if(closest == INT_MAX)
	{
		temp = s->a;
		while(temp)
		{
			if(content > s->max_a || content < s->min_a)
				return(s->min_a);
			if(temp->content > content && absolute_value(temp->content - content) < absolute_value(closest - content))
				closest = temp->content;
			temp = temp->next;
		}
	}
	if(closest == INT_MIN)
	{
		temp = s->b;
		while(temp)
		{
			if(content > s->max_b || content < s->min_b)
				return(s->max_b);
			else if(temp->content < content && absolute_value(temp->content - content) < absolute_value(closest - content))
				closest = temp->content;
			temp = temp->next;
		}
	}
	// printf("closest == %d\n", closest);
	return(closest);
}

int count(t_main *s, int closest, char c)
{
	int i;
	t_list *temp;

	i = 0;
	if (c == 'a')
		temp = s->a;
	else
		temp = s->b;
	while(temp)
	{
		if(temp->content == closest)
		{
			s->index_b  = i;
			return(i);
		}
		temp = temp->next;
		i++;
	}
	return(0);
}

void get_count_b(t_main *s)
{
	t_list *temp;
	int tmp_count;
	int temp_cost;

	temp_cost = 0;
	temp = s->a;
	tmp_count = 0;
	s->cost = INT_MAX;
	while(temp)
	{
		temp_cost = count(s, get_closest(s, temp->content, INT_MIN), 'b');
		if(s->index > (int)ft_lstsize(temp) / 2)
			temp_cost -= count(s, get_closest(s, s->a->content, INT_MIN), 'b');
		if(s->cost > temp_cost)
		{
			s->cost = temp_cost;
			s->index_a = tmp_count;
			s->index_b = count(s, get_closest(s, temp->content, INT_MIN), 'b');
		}
		tmp_count++;
		temp_cost++;
		temp = temp->next;
	}
}

void	spin_a(t_main *s)
{
	int x;

	x = 0;
	if(s->index_a > (int)ft_lstsize(s->a) / 2)
		x = 1;
	if(!x)
	{
		while(s->index_a)
		{
			rotate(s, 'a');
			s->index_a--;
		}
	}
	else
	{
		while(s->index_a <= (int)ft_lstsize(s->a))
		{
			reverse_rotate(s, 'a');
			s->index_a++;
		}
	}
}

void	spin_b(t_main *s)
{
	int x;

	x = 0;
	if(s->index_b > (int)ft_lstsize(s->b) / 2)
		x = 1;
	if(!x)
	{
		while(s->index_b)
		{
			rotate(s, 'b');
			s->index_b--;
		}
	}
	else
	{
		while(s->index_b <= (int)ft_lstsize(s->b))
		{
			reverse_rotate(s, 'b');
			s->index_b++;
		}
	}
}

void push_closest_to_a(t_main *s, int x, char c)
{
	int i;
	t_list *tmp;

	i = 0;
	if (c == 'a')
		tmp = s->a;
	else
		tmp = s->b;
	while(tmp->content != x)
	{
		tmp = tmp->next;
		i++;
	}
	if(i > (int)ft_lstsize(s->a) / 2)
	{
		while(i < (int)ft_lstsize(s->a))
		{
			reverse_rotate(s, 'a');
			i++;
		}
	}
	else
	{
		while(i)
		{
			rotate(s, 'a');
			i--;
		}
	}
}

void sort(t_main *s)
{
	push(s, 'b');
	push(s, 'b');
	while(s->a_lenght > 3)
	{
		get_count_b(s);
		spin_a(s);
		spin_b(s);
		push(s, 'b');
	}
	push_closest_to_a(s, s->max_b, 'b');
	two_ints(s, '3', 'a');
	while(s->b_lenght)
	{
		push_closest_to_a(s, get_closest(s, s->b->content, INT_MAX), 'a');
		push(s, 'a');
	}
	get_min_and_max_a(s);
	push_closest_to_a(s, s->min_a, 'a');
	printf("%d\n", sorted_check(s));
}
