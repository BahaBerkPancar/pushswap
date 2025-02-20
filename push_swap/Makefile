NAME = PUSH_SWAP

GIT_PRINTF = git@github.com:BahaBerkPancar/printf-42.git
GCC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF = printf/libftprintf.a
SRCS = ext/ft_atoi.c ext/ft_lst_second_last.c ext/ft_lstadd_back_bonus.c ext/ft_lstnew_bonus.c ext/ft_lstlast_bonus.c ext/ft_split.c ext/ft_substr.c ext/ft_strlen.c ext/memcpy.c ext/ft_strdup.c ext/ft_lstprint.c ext/ft_lstsize_bonus.c ext/ft_lstadd_front_bonus.c ext/ft_lstdelone_bonus.c main.c move.c ext.c first_second.c

all: $(NAME)

clone:
	@git clone $(GIT_PRINTF) printf
	@make -C printf > /dev/null 2>&1

$(NAME): 
	@$(GCC) $(CFLAGS) $(SRCS) $(PRINTF) -g -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

clear: fclean
	@clear && rm -rf PUSH_SWAP && rm -rf printf

push: all
	@make clean ; clear

fsanitize:
	@$(GCC) $(CFLAGS) $(SRCS) $(PRINTF) -fsanitize=address  -g -o $(NAME)