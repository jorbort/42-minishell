
NAME = minishell 

FLAGS = -Wall -Wextra -Werror -MMD 
SRC =	main.c token_parser.c token_lst.c token_splitter.c ft_errors.c lex_utils.c parser_utils.c parser.c

OBJS = $(SRC:.c=.o) 
DEPS = $(SRC:.c=.d)

RM = rm -f

MS = minishell.h
LIBFT_DIR = MyLibft
LIBFT =  MyLibft/libft.a
LIBS = $(MS) $(LIBFT)
READLINE_PATH:=	/goinfre/homebrew/opt/readline

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c $(MS) Makefile
	@$(CC) $(FLAGS) -g -I./includes -I./ -c $< -o $@ -I$(READLINE_PATH)/include

all:
	@$(MAKE) -C $(LIBFT_DIR) 
	@$(MAKE) -lreadline $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $@ -L$(READLINE_PATH)/lib -lreadline
	@echo "$(GREEN)MiniShell Compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) clean -C $(LIBFT_DIR) 
	@echo "$(RED)\nAll files deleted succesfully\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
