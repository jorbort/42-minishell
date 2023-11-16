NAME = libft.a
LIB = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Werror -Wall -Wextra

SRC = ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c	ft_memchr.c	ft_putendl_fd.c	ft_striteri.c ft_strncmp.c ft_touppper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRC_PRINT= ft_printf.c ft_putchar_par.c ft_putnbr_unsigned.c ft_putnbr.c ft_putnumber_base.c ft_putptr.c ft_putstr.c
SRC_GNL= get_next_line.c get_next_line_utils.c save_next_line.c save_next_line_utils.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_GNL=$(SRC_GNL:.c=.o)
OBJ_PRINT=$(SRC_PRINT:.c=.o)

INCLUDE = libft.h
ROBJ = *.o

%.o: %.c  $(INCLUDE)
	$(CC) $(CFLAGS) -c -I$(INCLUDE) -o $@ $< 

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS) $(OBJ_GNL) $(OBJ_PRINT)
	$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_GNL) $(OBJ_PRINT)

.PHONY : clean , fclean

clean : 
	$(RM) $(ROBJ) 

fclean : clean
	$(RM) $(NAME)

re : fclean all
