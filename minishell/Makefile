NAME = minishell 

FLAGS = -Wall -Wextra -Werror -MMD ##-fsanitize=address
SRC = 	src/main.c src/Tokenizer/token_parser.c src/Tokenizer/token_lst.c \
		src/Tokenizer/token_splitter.c  src/Tokenizer/token_utils.c \
		src/Parser/ft_errors.c src/Parser/lex_utils.c src/Parser/parser_utils.c src/Parser/parser_lst_utils.c \
		src/Parser/parser.c src/Parser/parse_redirs.c \
		src/Built_ins/built_in.c src/Built_ins/pwd.c src/Built_ins/cd.c src/Built_ins/env.c src/Built_ins/unset.c src/Built_ins/ft_exit.c src/Built_ins/echo.c\
		src/Built_ins/export.c src/Built_ins/export_utils.c src/Built_ins/export_utils_two.c src/Built_ins/export_utils_third.c\
		src/Utils/utils_general.c  src/Utils/utils_general_two.c\
		src/Expansor/expansor.c src/Expansor/expansor_utils.c src/Signals/signals.c \
		src/Heredoc/heredoc.c \
		src/Executor/exec_redirs.c src/Executor/exec_utils.c src/Executor/executor.c src/Executor/ft_executor.c \
		src/Executor/path_utils.c \


OBJS = $(SRC:.c=.o) ##$(SRC_TOKENIZER:.c=.o) $(SRC_PARSER:.c=.o) 
DEPS = $(SRC:.c=.d) ##$(SRC_TOKENIZER:.c=.d) $(SRC_PARSER:.c=.d)

RM = rm -f

MS = ./includes/minishell.h 

LIBFT_DIR = libraries/MyLibft
LIBFT =  libraries/MyLibft/libft.a
LIBS = $(MS) $(LIBFT) 
READLINE_PATH:=	libraries/readline
LIB_A		:=	$(READLINE_PATH)/libreadline.a $(READLINE_PATH)/libhistory.a \
				$(LIBFT_DIR)/libft.a
LIB_ADD_DIR	:=	-L$(READLINE_PATH) -L$(LIBFT_DIR)
LIB_SEARCH	:=	-lreadline -lhistory -lncurses -lft

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
PURPLE =\033[0;35m      

%.o: %.c $(MS) Makefile
	@$(CC) $(FLAGS) -DREADLINE_LIBRARY=1 -g -I$(READLINE_PATH) -I./includes -I./ -c $< -o $@ 
all:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) rdline --no-print-directory
	@$(MAKE) -lreadline $(NAME) --no-print-directory
	

$(NAME):: $(OBJS) 
	@$(CC) $(FLAGS) $(OBJS) $(LIB_ADD_DIR) $(LIB_SEARCH) $(LIB_A) -o $@
	@echo "$(GREEN)MiniShell Compiled$(NC)"

$(NAME)::
	@echo -n

rdline :
	@echo "${PURPLE}Compiling Readline...${NC}"
	@cd ./libraries/readline/ &> /dev/null && ./configure &> /dev/null
	@make -C ./libraries/readline/ &> /dev/null
	@echo "${GREEN}Readline Compiled${NC}"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) clean -C $(LIBFT_DIR) 
	@echo "$(RED)\nAll files deleted succesfully\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBFT)
	@$(MAKE) -C $(READLINE_PATH) clean --no-print-directory

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
