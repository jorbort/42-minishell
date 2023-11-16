NAME=pipex
BONUS = pipex_bonus

CFLAGS= -Wall -Werror -Wextra -g
CC = gcc

SRC_1=	pipex.c\
		pipex_utils.c\

BONUS_SRC=	pipex_bonus.c\
			utils_bonus.c\
			path_bonus.c\

LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

OBJECTS_1= $(SRC_1:.c=.o)
BONUS_OBJ = ${BONUS_SRC:.c=.o}

HEADER = pipex.h
HEADER_BONUS=pipex_bonus.h


all: subsystems $(NAME) 
bonus : subsystems $(BONUS)

subsystems:
		make -C $(LIBFT_PATH) all

%.o: %.c	$(HEADER) 
	$(CC) $(CFLAGS)  -c -o  $@ $<

$(NAME): $(OBJECTS_1) $(HEADER)
	$(CC) $(CFLAGS)  $(OBJECTS_1) $(LIBFT_LIB) -o $(NAME) 

$(BONUS): $(BONUS_OBJ) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_LIB) -o $(BONUS) 

clean : 
	make -C $(LIBFT_PATH) clean
	rm -f *.o

fclean : clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all re clean fclean bonus