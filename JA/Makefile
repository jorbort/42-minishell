
NAME = minishell 

FLAGS = -Wall -Wextra -Werror -MMD 
SRC =	src/main.c src/tokenizer/token_parser.c src/tokenizer/token_lst.c \
		src/tokenizer/token_splitter.c  src/tokenizer/token_utils.c

OBJS = $(SRC:.c=.o) 
DEPS = $(SRC:.c=.d)

RM = rm -f

MS = ./includes/minishell.h
LIBFT_DIR = libraries/MyLibft
LIBFT =  libraries/MyLibft/libft.a
LIBS = $(MS) $(LIBFT)
READLINE_PATH:=	/goinfre/homebrew/opt/readline

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c $(MS) Makefile
	@$(CC) $(FLAGS) -g -I./includes -I./ -c $< -o $@ -I$(READLINE_PATH)/include -I ($LIBFT_DIR)

all:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) -lreadline $(NAME) --no-print-directory

$(NAME):: $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $@ -L$(READLINE_PATH)/lib -lreadline
	@echo "$(GREEN)MiniShell Compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS) --no-print-directory
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory 
	@echo "$(RED)\nAll files deleted succesfully\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
