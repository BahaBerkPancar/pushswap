#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "./printf/ft_printf.h"
#include <limits.h>


typedef struct s_list
{
	int content;
	struct s_list *next;	
}	t_list;

typedef struct s_main
{
	t_list	*a;
	size_t	a_lenght;
	t_list	*b;
	size_t	b_lenght;
	size_t	step_count;
	int		min_a;
	int		min_b;
	int		max_a;
	int		max_b;
	int		count;
	int		a_index;
	int		b_index;
	int		index_a;
	int		index_b;
	int		cost;
	int		flag;
}		t_main;


char	*ft_strjoin(char const *s1, char const *s2);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
size_t	ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *src);
void 	ft_lstprint(t_list *lst);
t_list	*ft_lst_second_last(t_list *lst);
void	errors(char *c);
void	swap(t_main *s, char c);
int		ft_isdigit(char *str);
void	get_args(t_main *s, char **temp);
void	rotate(t_main *s, char c);
void	reverse_rotate(t_main *s, char c);
void	push(t_main *s, char c);
int		distance_a(t_main *s);
int		distance_b(t_main *s);
void	two_ints(t_main *s, char x, char c);
void	get_min_and_max_a(t_main *s);
void	get_min_and_max_b(t_main *s);
void	sort(t_main *s);
void	sort_a(t_main *s);
int		sorted_check(t_main *s);
int		count(t_main *s, int closest, char c);
int		get_closest(t_main *s, int content, int closest);
void	join_split_and_check(t_main *s, char *av[], int flag);
int		absolute_value(int a);
int		ft_strcmp(char *s1, char *s2);
void	s_free(t_main *s);

#endif