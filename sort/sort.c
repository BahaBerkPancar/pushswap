#include "../push_swap.h"

void sort_a(t_main *s)
{
	if (s->a_lenght == 2)
		two_ints(s, '2', 'a');
	if (s->a_lenght == 3)
		two_ints(s, '3', 'a');
	s_free(s);
}

int total_count(int a, int b)
{
	int true_a;
	int true_b;

	if (a < 0)
		true_a = -a;
	else
		true_a = a;
	if (b < 0)
		true_b = -b;
	else
		true_b = b;
	if ((a < 0 && b < 0) || (a > 0 && b > 0))
	{
		if (true_a > true_b)
			return (true_a);
		return (true_b);
	}
	return (true_a + true_b);
}

int index_find(t_list *lst, int content)
{
	int length;
	t_list *temp;
	int i;
	int flag;

	flag = 1;
	length = ft_lstsize(lst) / 2;
	temp = lst;
	i = 0;
	while (temp)
	{
		if (temp->content == content)
			return (i);
		if (i >= length && flag)
		{
			i = -i;
			flag = 0;
			i--;
		}
		i++;
		temp = temp->next;
	}
	return (0);
}

int closest_b(t_main *s, int content)
{
	t_list *temp;
	int value;

	value = -2147483648;
	get_min_and_max_b(s);
	if (content < s->min_b)
		return (s->max_b);
	temp = s->b;
	while (temp)
	{
		if (content > temp->content && temp->content > value)
			value = temp->content;
		temp = temp->next;
	}
	return (value);
}

void push_one(t_main *s, int index, char flag)
{
	while (index != 0)
	{
		if (index < 0 && flag == 'a')
		{
			reverse_rotate(s, 'a');
			index++;
		}
		else if (index > 0 && flag == 'a')
		{
			rotate(s, 'a');
			index--;
		}
		else if (index < 0 && flag == 'b')
		{
			reverse_rotate(s, 'b');
			index++;
		}
		else if (index > 0 && flag == 'b')
		{
			rotate(s, 'b');
			index--;
		}
	}
}

void push_to_b(t_main *s, int index_a, int index_b)
{
	if ((s->a < 0 && s->b < 0))
	{
		while ((index_a < 0 && index_b < 0) && (index_a != 0 && index_b != 0))
		{
			reverse_rotate(s, 'r');
			index_a++;
			index_b++;
		}
	}
	if (s->a > 0 && s->b > 0)
	{
		while ((index_a > 0 && index_b > 0) && (index_a != 0 && index_b != 0))
		{
			rotate(s, 'r');
			index_a--;
			index_b--;
		}
	}
	if (index_a != 0)
		push_one(s, index_a, 'a');
	if (index_b != 0)
		push_one(s, index_b, 'b');
	push(s, 'b');
}

int move_calculator(t_list **a, int content)
{
	t_list *temp;
	int i;

	i = 0;
	temp = *a;
	while (temp)
	{
		if (temp->content == content)
			break;
		i++;
		temp = temp->next;
	}
	if ((int)ft_lstsize(*a) / 2 > i)
		return (i);
	else
		return (((int)ft_lstsize(*a) - i) * -1);
}

void move_calc_b(t_main *s)
{
	int final_move;
	int a_index;
	int b_index;
	int a_count;
	t_list *tmp;

	tmp = s->a;
	final_move = INT_MAX;
	while (tmp)
	{
		a_count = move_calculator(&s->a, tmp->content);
		if (total_count(a_count, move_calculator(&s->b, closest_b(s, tmp->content))) < final_move)
		{
			final_move = total_count(a_count, move_calculator(&s->b, closest_b(s, tmp->content)));
			a_index = a_count;
			b_index = move_calculator(&s->b, closest_b(s, tmp->content));
		}
		tmp = tmp->next;
	}
	push_to_b(s, a_index, b_index);
}

int get_closest(t_main *s, int content, int closest)
{
	t_list *temp;

	get_min_and_max_a(s);
	get_min_and_max_b(s);
	if (closest == INT_MAX)
	{
		temp = s->a;
		while (temp)
		{
			if (content > s->max_a || content < s->min_a)
				return (s->min_a);
			if (temp->content > content && absolute_value(temp->content - content) < absolute_value(closest - content))
				closest = temp->content;
			temp = temp->next;
		}
	}
	if (closest == INT_MIN)
	{
		temp = s->b;
		while (temp)
		{
			if (content > s->max_b || content < s->min_b)
				return (s->max_b);
			else if (temp->content < content && absolute_value(temp->content - content) < absolute_value(closest - content))
				closest = temp->content;
			temp = temp->next;
		}
	}
	return (closest);
}

void push_closest_to_a(t_main *s, int x, char c)
{
	int i;
	t_list *tmp;

	i = 0;
	(void)i;
	(void)x;
	(void)tmp;
	if (c == 'a')
		tmp = s->a;
	else
		tmp = s->b;
	while (tmp->content != x)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (int)ft_lstsize(s->a) / 2)
	{
		while (i < (int)ft_lstsize(s->a))
		{
			reverse_rotate(s, 'a');
			i++;
		}
	}
	else
	{
		while (i)
		{
			rotate(s, 'a');
			i--;
		}
	}
}

void s_free(t_main *s)
{
	if (s->a)
		ft_lstclear(&s->a);
	free(s);
}

void sort(t_main *s)
{
	push(s, 'b');
	if (s->a_lenght > 3)
		push(s, 'b');
	while (s->a_lenght > 3)
		move_calc_b(s);
	get_min_and_max_b(s);
	push_closest_to_a(s, s->max_b, 'b');
	two_ints(s, '3', 'a');
	while (s->b_lenght)
	{
		push_closest_to_a(s, get_closest(s, s->b->content, INT_MAX), 'a');
		push(s, 'a');
	}
	get_min_and_max_a(s);
	push_closest_to_a(s, s->min_a, 'a');
	printf("%d\n", sorted_check(s));
	s_free(s);
}
