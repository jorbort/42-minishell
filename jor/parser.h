/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:33:03 by jorge             #+#    #+#             */
/*   Updated: 2023/10/19 09:18:45 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

typedef struct s_lexer
{
	char	*str;
	char	*token;
	int		i;
	t_lexer	*next;
	t_lexer	*prev;
}t_lexer;

typedef struct s_redir
{
	char			*redirection;
	char			*in;
	char			*out;
	t_redir			*next;
	t_redir			*prev;
}	t_redir;

typedef struct s_cmd
{
	char			*cmd;
	char			**str;
	char			*args;
	t_redir			*redirection;
	char			*here_d_file_name;
	bool			built_in;
	int				id;
	t_cmd			*next;
	t_cmd			*prev;
}	t_cmd;

typedef struct s_data
{
	char	*args;
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
	struct s_data *data;
	struct s_cmd  *cmd;
}t_program;


#endif