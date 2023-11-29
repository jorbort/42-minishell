/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:41:54 by juan-anm          #+#    #+#             */
/*   Updated: 2023/11/29 10:08:45 by juanantonio      ###   ########.fr       */
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
# include <libraries/readline/readline.h>
# include <libraries/readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/param.h>
# include <signal.h>
/////////////ERROR MGS////////////////

# define TOKEN_ERROR "minishell ERROR: invalid consecutive tokens "
# define PIPE_ERROR "minishell ERROR: invalid | or consecutive | "
# define INVALID_ARG "minishell ERROR: invalid arguments"

/////////// KEYS /////////////

# define CTRL_C		SIGINT
# define CTRL_SLASH	SIGQUIT

/////////////COLORS////////////////

# define WHITE_T		"\x1b[1;37m"
# define YELLOW_T		"\x1b[1;33m"
# define RESET_COLOR	"\x1b[0m"
# define BLUE_T			"\x1b[1;36m"

/////////////////// TOKENIZER STRUCTS /////////////////////////


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

/////////////////// PARSER STRUCTS /////////////////////////

typedef struct s_parser
{
	t_lexer				*lexer_list;
	t_lexer				*redirections;
	int					num_redirections;
	struct s_program	*program;
}	t_parser;


typedef struct s_cmd
{
	char			**cmd;
	int				num_redirs;
	t_lexer			*redirection;
	char			*here_d_file_name;
	bool			built_in;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_data
{
	char	*args;
	int		nume_redirs;
	char	**paths;
	char	**envp;
	t_cmd	*simple_cmd;
	char	*pwd;
	char	*prev_pwd;
	int		pipes;
	int		*pid;
	bool	heredoc;
}	t_data;

typedef struct s_program
{
	struct s_data			*data;
	struct s_cmd			*cmd_list;
	struct s_lexer			*lex_list;
	struct s_lexer			*redir;
}	t_program;

///////////////TOKENIZER *.c///////////////

t_lexer		*tokenizer(t_lexer **lexer, char *str);
t_lexer		*lex_lstlast(t_lexer *lst);
int			lex_lstsize(t_lexer *lst);
void		lex_lstclear(t_lexer **lst);
void		lex_lstadd_back(t_lexer **lst, t_lexer *node);
t_lexer		*lex_lstnew(void);
void		check_pipes(t_lexer **lexer);
char		**ft_pipesplit(char const *s);
int			ft_isspchar(char c);
char		*ft_pipestrdupli(char *s, int reset);
int			ft_pipecntwrds(char const *s);
char		**ft_pipesplipri(char **split, char *s);
int			cntallwrds(int i, int contl, int contw, char *s);
int			dupstrlen(char *s, int i);

//parser.c
bool		ft_parser(t_program *program);
//parser_lst_utils.c
t_cmd		*t_cmd_new(char **str_cmd, int num_redirs, t_lexer *redirection);
void		ft_cmd_addback(t_cmd **lst, t_cmd *node);
void		ft_lexeradd_back(t_lexer **lst, t_lexer *node);
void		cmd_clear(t_cmd **list);
//parser_utils.c
t_parser	init_parser(t_lexer *lex_list, t_program *program);
void		ft_count_pipes(t_lexer *lex_list, t_program *program);
int			count_args(t_lexer *lex_list);
//lex_utils.c
void		ft_lexerdelone(t_lexer **lex_list, int to_del);
t_lexer		*ft_lexclear_one(t_lexer **lex_list);
void		ft_lexerdel_first(t_lexer **lex_list);
void		ft_lexclear(t_lexer **lex_list);
t_lexer		*ft_lex_new(char *str, int token);
//ft_errors.c
bool		ft_error(t_program *program, int errno);
//parse_redirs.c
int			add_redir(t_lexer *tmp, t_parser *pars);
void		del_redirs(t_parser *pars);

/////Built-ins//////

//pwd.c
void		print_wd(t_data *data);
//env.c
void		print_env(t_program *program);
//cd.c
bool		change_dir(t_program *program, t_cmd *cmd_list);
//built_in.c
void		is_builtin(t_program *program);
void		exec_builtin(t_program *program);
////Utils///
char		**ft_arrdup(char **arr);
void		change_path(t_program *program);
bool		invalid_unsetchar(char *str);
//utils_general.c
char		**ft_arrdup(char **arr);
void		change_path(t_program *program);
void		free_double_arr(char **arr);
bool		invalid_unsetchar(char *str);
//echo.c
void		print_cmd(int i, char **str, int fd);
bool		ft_echo(t_cmd *cmd_list);
//unset.c
bool		ft_unset(t_program *program, t_cmd *cmd_list);
//ft_exit.c
void		free_program(t_program *program);
bool		ft_exit(t_program *program, t_cmd *cmd_list);
/////Expansor///////
void		ft_expand(t_program *program);
char		*ft_get_varname(char *str, int i);
int			ft_search_quote(char *str);
char		*get_myenv(t_program *program, char *var);
void		ft_expand_var(t_program *program, int i, int c, char *str);
char		*ft_return_var(t_program *program, char *cmd, char *str, int c);

/////////Signals////////////////

int			init_signals(int mode);

#endif
