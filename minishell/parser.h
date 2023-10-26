/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:33:03 by jorge             #+#    #+#             */
/*   Updated: 2023/10/26 09:43:35 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdbool.h>
# include "minishell.h"

# define TOKEN_ERROR "minishell ERROR: invalid consecutive tokens "
# define PIPE_ERROR "minishell ERROR: invalid | or consecutive | "
# define INVALID_ARG "minishell ERROR: invalid arguments"

typedef struct s_cmd
{
	char			**cmd;
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
	bool	reset;
}	t_data;

typedef struct s_program
{
	t_data			*data;
	t_cmd			*cmd_list;
	t_lexer			*lex_list;
	t_lexer			*redir;
}	t_program;

//parser.c
bool	ft_parser(t_program *program);
//parser_utils.c
t_cmd	*t_cmd_new(char **str, t_lexer *redirection);
void	ft_cmd_addback(t_cmd **lst, t_cmd *new);
/*void	ft_cmd_rmfirst(t_cmd **lst);*/
int	count_args(t_program *program);
void	ft_count_pipes(t_program *program);
//lex_utils.c
void	ft_lexerdelone(t_lexer *lex_list, int to_del);
t_lexer	*ft_lexclear_one(t_lexer *lex_list);
void	ft_lexerdel_first(t_lexer *lex_list);
void	ft_lexclear(t_lexer *lex_list);
t_lexer	*ft_lex_new(char *str, int token);
//ft_errors.c
void	ft_error(t_program *program, int errno);



#endif