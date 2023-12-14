/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/12/14 01:22:50 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

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
		return (ft_error(pars->program, 0), NULL);
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
	return (t_cmd_new(str, pars->num_redirections, pars->redirections));
}

int	check_pipes_syntax(t_lexer *lexer, t_program *program)
{
	if (lexer->token == PIPE)
	{
		if (lexer->prev == NULL)
		{
			ft_error(program, PIPE);
			return (1);
		}
		if (lexer->next && lexer->next->token == PIPE)
		{
			ft_error(program, PIPE);
			return (1);
		}
		else if (!lexer->next)
		{
			ft_error(program, NONE);
			return (1);
		}
	}
	return (0);
}

int	check_duplicates(t_lexer *lexer, t_program *program)
{
	if (lexer->token >= 2 && lexer->token <= 5)
	{
		if (lexer->next == NULL)
		{
			ft_error(program, 0);
			return (1);
		}
		else if (lexer->next->token != NONE)
		{
			if (lexer->next->token == PIPE)
				ft_error(program, PIPE);
			else if (lexer->next->token == LESS)
				ft_error(program, LESS);
			else if (lexer->next->token == LESS_LESS)
				ft_error(program, LESS_LESS);
			else if (lexer->next->token == GREAT)
				ft_error(program, GREAT);
			else if (lexer->next->token == GREAT_GREAT)
				ft_error(program, GREAT_GREAT);
			return (1);
		}
	}
	return (0);
}

int	check_syntax(t_lexer *lexer, t_program *program)
{
	while (lexer)
	{
		if (lexer->token != NONE)
		{
			if (check_duplicates(lexer, program)
				|| check_pipes_syntax(lexer, program))
			{
				(*program->exit_code) = 2;
				return (1);
			}
		}
		lexer = lexer->next;
	}
	return (0);
}

int	ft_parser(t_program *program)
{
	t_cmd		*node;
	t_parser	aux;

	program->cmd_list = NULL;
	ft_count_pipes(program->lex_list, program);
	if (check_syntax(program->lex_list, program))
		return (1);
	while (program->lex_list)
	{
		if (program->lex_list && program->lex_list->token == PIPE)
			ft_lexerdelone(&program->lex_list, program->lex_list->i);
		aux = init_parser(program->lex_list, program);
		node = init_cmd(&aux);
		if (!node)
			return (ft_error(program, 0));
		if (!program->cmd_list)
			program->cmd_list = node;
		else
			ft_cmd_addback(&program->cmd_list, node);
		program->lex_list = aux.lexer_list;
	}
	program->redir = aux.redirections;
	return (0);
}
