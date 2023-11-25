/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:41:54 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/26 12:41:47 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libraries/MyLibft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

typedef enum s_token
{
	NONE = 0,
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS
}	t_token;

typedef struct s_lexer
{
	char			*str;
	t_token			token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

//////TOKENIZER/////////

t_lexer	*tokenizer(t_lexer **lexer, char *str);
t_lexer	*lex_lstlast(t_lexer *lst);
int		lex_lstsize(t_lexer *lst);
void	lex_lstclear(t_lexer **lst);
void	lex_lstadd_back(t_lexer **lst, t_lexer *new);
t_lexer	*lex_lstnew(void);
void	check_pipes(t_lexer **lexer);
char	**ft_pipesplit(char const *s);
int		ft_isspchar(char c);
char	*ft_pipestrdupli(char *s, int reset);
int		ft_pipecntwrds(char const *s);
char	**ft_pipesplipri(char **split, char *s);
int		cntallwrds(int i, int contl, int contw, char *s);
int		dupstrlen(char *s, int i);

# define WHITE_T		"\x1b[1;37m"
# define YELLOW_T		"\x1b[1;33m"
# define RESET_COLOR	"\x1b[0m"
# define BLUE_T			"\x1b[1;36m"

#endif