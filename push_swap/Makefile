NAME = PUSH_SWAP

GCC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = ext/ft_atoi.c ext/ft_lstadd_back_bonus.c ext/ft_lstnew_bonus.c ext/ft_lstlast_bonus.c ext/ft_split.c ext/ft_substr.c ext/ft_strlen.c ext/memcpy.c ext/ft_strdup.c ext/ft_lstprint.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS)  -o $(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

clear: fclean
	clear && rm -rf a.out

push: all
	make clean ; clear