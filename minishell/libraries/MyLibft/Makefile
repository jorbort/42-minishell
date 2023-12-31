# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorge <jorge@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 11:15:53 by juan-anm          #+#    #+#              #
#    Updated: 2023/10/30 19:37:00 by jorge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BNAME = .bonus
CFLAGS = -Wall -Wextra -Werror -g

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strchr.c ft_strrchr.c ft_memmove.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_atol.c \
	ft_isapipe.c ft_isspace.c ft_isaquote.c \
	
SRCSBONUS =  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstdelone_bonus.c  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c  ft_lstadd_back_bonus.c \

SRCSGNL = get_next_line_utils_bonus.c get_next_line_bonus.c \

SRCSPRINTF = ft_printf.c ft_printbase.c ft_printchars.c ft_printnum.c \

INCLUDE = libft.h

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)
OBJSGNL = $(SRCSGNL:.c=.o)
OBJSPRINTF = $(SRCSPRINTF:.c=.o)

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

RM = rm -f
DEPS = $(SRCS:.c=.d)
DEPSBONUS = $(SRCSBONUS:.c=.d)
DEPSGNL = $(SRCSGNL:.c=.d)
DEPSPRINTF = $(SRCSPRINTF:.c=.d)

%.o: %.c $(INCLUDE) Makefile
	@$(CC) $(CFLAGS) -MMD  -c $< -o $@
	
all: $(NAME)

$(NAME)::$(OBJS) $(OBJSBONUS) $(OBJSGNL) $(OBJSPRINTF)
	@ar crs $(NAME) $(OBJS) $(OBJSBONUS) $(OBJSGNL) $(OBJSPRINTF)
	@echo "$(GREEN)MyLibft compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJSBONUS) $(DEPSBONUS) $(OBJSGNL) $(DEPSGNL) $(OBJSPRINTF) $(DEPSPRINTF)
	@echo "$(RED)MyLibft objects destroyed$(NC)"

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include ${DEPS}
-include $(DEPSBONUS)
-include $(DEPSPIRNTF)
-include $(DEPSGNL)
