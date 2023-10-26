NAME = minishell 

FLAGS = -Wall -Wextra -Werror -MMD 
SRC = 	src/main.c src/Tokenizer/token_parser.c src/Tokenizer/token_lst.c \
		src/Tokenizer/token_splitter.c  src/Tokenizer/token_utils.c \
		src/Parser/ft_errors.c src/Parser/lex_utils.c src/Parser/parser_utils.c \
		src/Parser/parser.c \

OBJS = $(SRC:.c=.o) ##$(SRC_TOKENIZER:.c=.o) $(SRC_PARSER:.c=.o) 
DEPS = $(SRC:.c=.d) ##$(SRC_TOKENIZER:.c=.d) $(SRC_PARSER:.c=.d)

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
