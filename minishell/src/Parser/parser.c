/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/11/13 12:38:37 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*init_cmd(t_parser *pars)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	del_redirs(pars);
	arg_size = count_args(pars->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		ft_error(pars->program, 3);
	tmp = pars->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&pars->lexer_list, tmp->i);
			tmp = pars->lexer_list;
		}
		arg_size--;
	}
	return (t_cmd_new(str,pars->num_redirections,pars->redirections));
}

static bool	pipe_error(t_program *program, t_token token)
{
	if (token == PIPE)
	{
		ft_error(program,1);
		return (false);
	}
	if (!program->lex_list)
	{
		ft_error(program,3);
		return (false);
	}
	return (true);
}

bool	ft_parser(t_program *program)
{
	t_cmd		*node;
	t_parser	aux;

	program->cmd_list = NULL;
	ft_count_pipes(program->lex_list, program);
	if (program->lex_list->token == PIPE)
		return(ft_error(program, 1));
	while (program->lex_list)
	{
		if (program->lex_list && program->lex_list->token == PIPE)
			ft_lexerdelone(&program->lex_list, program->lex_list->i);
		if (!pipe_error(program, program->lex_list->token))
			return (false);
		aux = init_parser(program->lex_list, program);
		node = init_cmd(&aux);
		if (!node)
			ft_error(program, 3);
		if (!program->cmd_list)
			program->cmd_list = node;
		else
			ft_cmd_addback(&program->cmd_list, node);
		program->lex_list = aux.lexer_list;
	}
	return (true);
}
