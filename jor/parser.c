/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/10/22 23:51:42 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_parser(t_program	*program )
{
	if (program->lex_list->token == PIPE)
		ft_pipe_error();
	count_pipes(program);
	parse_tokens(program);
}

void	get_redir(t_program *program, t_token token)
{
	t_lexer *node;
	t_lexer *tmp;
	int		index_a;
	int		index_b;


	if (token < GREAT)
		ft_pipe_error(program);
	else if (token >= GREAT && token <= LESS_LESS)
	{
		tmp = program->lex_list;
		node = ft_lexer_new(ft_strdup(tmp->next->str), tmp->token);
		if (!node)
			ft_parser_error();
		ft_lexeradd_back(program->redir, node);
		index_a = tmp->i;
		index_b = tmp->next->i;
		ft_lexerdelone(program->lex_list, index_a);
		ft_lexerdelone(program->lex_list, index_b);
		free(node);
	}
}

t_cmd	*get_cmd(t_program *program)
{
	char	**str;
	int		i;
	t_lexer *tmp;
	int 	args;

	i = 0;
	args = count_args(program);
	str = ft_calloc(args + 1, sizeof(char *));
	if(!str)
		parser_error();//to-do
	tmp = program->lex_list;
	while (args)
	{
		if(tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(program->lex_list, tmp->i);
			tmp = program->lex_list;
		}
		args--;
	}
	return (t_cmd_new(str, program->redir));
}

void	parse_tokens(t_program *program)
{
	t_cmd	*node;

	program->data->pipes = count_pipes();//to-do funcion que cuente los pipes para saber el numero de comandos 	
	get_redir(program ,program->lex_list->token); 
	if (is_pipe(program->lex_list->token) == true)
		ft_pipe_error(program->lex_list);
	while (program->lex_list)
	{
		if (program->lex_list && program->lex_list->token == PIPE)
			ft_lexerdelone(program->lex_list, program->lex_list->i);
		if (program->lex_list->token == PIPE)
			ft_double_pipe_error(program);
		node = get_cmd(program);
		if (!node)
			parser_error();
		if (!program->cmd_list)
			program->cmd_list = node;
		else
			ft_cmd_addback(program->cmd_list, node);
		free(node);
	}
}

