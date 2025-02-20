#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "./printf/ft_printf.h"


typedef struct s_list
{
	int content;
	struct s_list *next;	
}	t_list;

typedef struct s_main
{
	int count;
	t_list *a;
	size_t a_lenght;
	t_list *b;
	size_t b_lenght;
	size_t step_count;
}		t_main;


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
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
void	get_args(t_main *s, char *av[], int flag);

void	swap(t_main *s, char c);
void rotate(t_main *s, char c);
void reverse_rotate(t_main *s, char c);
void push(t_main *s, char c);

void two_ints(t_main *s, char x);

#endif