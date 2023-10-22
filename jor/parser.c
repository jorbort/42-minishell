/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/10/22 16:23:29 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_parser(t_program	*program )
{
	if (program->lex_list->token == PIPE)
		ft_pipe_error();
	parse_tokens(program);
}

bool	is_redir(t_program *program, t_token token)
{
	t_lexer *node;
	t_lexer *tmp;
	int		index_a;
	int		index_b;


	if (token < GREAT)
		return (false);
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
		return (true);
	}
}


void	parse_tokens(t_program *program)
{
	program->data->pipes = count_pipes();//to-do funcion que cuente los pipes para saber el numero de comandos 
	while (program->lex_list)
	{
		is_redir(program ,program->lex_list->token); 
		if (is_pipe(program->lex_list->token) == true)
			ft_pipe_error(program->lex_list);
		if (program->lex_list->str)
		{
			program->cmd_list->str = ft_strdup(program->lex_list->str);
			ft_lexerdelone(program->lex_list, program->lex_list->i);
		}
	}
}
