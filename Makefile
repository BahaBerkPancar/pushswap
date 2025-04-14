NAME = push_swap

GIT_PRINTF = git@github.com:BahaBerkPancar/printf-42.git
GCC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = printf/libftprintf.a
SRCS = ext/libft/ft_isdigit.c ext/libft/ft_strcmp.c  sort/rotate_rev.c ext/libft/ft_lstclear_bonus.c ext/libft/ft_atoi.c ext/libft/ft_strjoin.c ext/libft/ft_lst_second_last.c ext/libft/ft_lstadd_back_bonus.c ext/libft/ft_lstnew_bonus.c ext/libft/ft_lstlast_bonus.c ext/libft/ft_split.c ext/libft/ft_substr.c ext/libft/ft_strlen.c ext/libft/memcpy.c ext/libft/ft_strdup.c ext/libft/ft_lstprint.c ext/libft/ft_lstsize_bonus.c ext/libft/ft_lstadd_front_bonus.c ext/libft/ft_lstdelone_bonus.c main.c sort/move.c ext/ext.c sort/sort2_3.c sort/sort.c
OBJDIR = .obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)


#################################################### COLORS ####################################################
################################################################################################################
COLOR_BLACK         =   \033[0;30m
COLOR_BOLD_BLACK    =   \033[1;30m
COLOR_LIGHT_BLACK   =   \033[0;90m
COLOR_WHITE         =   \033[0;37m
COLOR_BOLD_WHITE    =   \033[1;37m
COLOR_LIGHT_WHITE   =   \033[0;97m
COLOR_GRAY          =   \033[0;90m
COLOR_BOLD_GRAY     =   \033[1;30m
COLOR_LIGHT_GRAY    =   \033[0;37m
COLOR_YELLOW        =   \033[0;33m
COLOR_BOLD_YELLOW   =   \033[1;33m
COLOR_LIGHT_YELLOW  =   \033[0;93m
COLOR_RED           =   \033[0;31m
COLOR_BOLD_RED      =   \033[1;31m
COLOR_LIGHT_RED     =   \033[0;91m
COLOR_GREEN         =   \033[0;32m
COLOR_BOLD_GREEN    =   \033[1;32m
COLOR_LIGHT_GREEN   =   \033[0;92m
COLOR_BLUE          =   \033[0;34m
COLOR_BOLD_BLUE     =   \033[1;34m
COLOR_LIGHT_BLUE    =   \033[0;94m
COLOR_PURPLE        =   \033[0;35m
COLOR_BOLD_PURPLE   =   \033[1;35m
COLOR_LIGHT_PURPLE  =   \033[0;95m
COLOR_CYAN          =   \033[0;36m
COLOR_BOLD_CYAN     =   \033[1;36m
COLOR_LIGHT_CYAN    =   \033[0;96m
COLOR_RESET         =   \033[0m
################################################################################################################
################################################################################################################


check_dir:
	@if [ ! -d "printf" ]; then \
		clear; \
		echo "$(COLOR_RED)You need to clone printf! ❌"; \
		echo "$(COLOR_YELLOW) Running 'make clone'"; \
		$(MAKE) clone;\
		$(MAKE) $(NAME);\
	else \
		$(MAKE) $(NAME); \
	fi

#Making the object directory -p creates (if it doesn't exist, and silences warning)
$(OBJDIR):
	@mkdir -p $(OBJDIR)

#Compiling OBJS files into OBJDIR
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(GCC) $(CFLAGS) -c $< -o $@

all: check_dir $(NAME)

clone:
	@echo "$(COLOR_GREEN)@ Cloning Printf..."
	@git clone $(GIT_PRINTF) printf
	@make -C printf > /dev/null 2>&1
	@echo "$(COLOR_GREEN)@ Cloned Printf ✅"
	@clear

$(NAME): $(OBJS)
	@$(GCC) $(CFLAGS) $(OBJS) $(PRINTF) -g -o $(NAME)
	@clear
	@echo "$(COLOR_BLACK)@ DONE $(NAME) ✅"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(COLOR_RED)@ Cleaned All Objects"
	@sleep 2
	@clear

fclean: clean
	@rm -rf $(NAME)
	@echo "$(COLOR_RED)@ Cleaned $(NAME)"
	@sleep 2
	@clear

re: fclean
	@$(MAKE) all
	@sleep 1
	@echo "$(COLOR_GREEN)@ Remade ♲"


clear: fclean
	@rm -rf printf
	@echo "$(COLOR_RED)@ Cleaned Printf"
	@sleep 1
	@clear
	@echo "$(COLOR_BOLD_RED)🌀 You Have Cleared Everything 🚮"
	@sleep 2
	@clear

push: all
	@make clean ; clear

fsanitize:
	@$(GCC) $(CFLAGS) $(OBJS) $(PRINTF) -fsanitize=address -g -o $(NAME)