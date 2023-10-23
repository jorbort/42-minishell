/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:33:03 by jorge             #+#    #+#             */
/*   Updated: 2023/10/23 12:54:44 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdbool.h>
# include "JA/includes/minishell.h"

typedef struct s_cmd
{
	char			**cmd;
	t_lexer			*redirection;
	char			*here_d_file_name;
	bool			built_in;
	t_cmd			*next;
	t_cmd			*prev;
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


#endif