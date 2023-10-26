/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/10/26 15:00:47 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_redir(t_program *program, t_lexer *tmp)
{
	t_lexer	*node;
	int		index_a;
	int		index_b;

	tmp = program->lex_list;
	node = ft_lex_new(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
	{
		ft_error(program, 1);
		return ;
	}
	lex_lstadd_back(&program->redir, node);
	index_a = tmp->i;
	index_b = tmp->next->i;
	ft_lexerdelone(program->lex_list, index_a);
	ft_lexerdelone(program->lex_list, index_b);
	program->data->nume_redirs++;
	free(node);
}

static void	del_redirs(t_program *program)
{
	t_lexer	*tmp;

	tmp = program->lex_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
	{
		ft_error(program, 1);
		return ;
	}
	if (tmp->next->token)
	{
		ft_error(program, 3);
		return ;
	}
	if ((tmp->token >= GREAT && tmp->token <= LESS_LESS))
		get_redir(program, tmp);
	del_redirs(program);
}

static t_cmd	*get_cmd(t_program *program)
{
	char	**str;
	int		i;
	t_lexer	*tmp;
	int		args;

	i = 0;
	args = count_args(program);
	str = ft_calloc(args + 1, sizeof(char *));
	if (!str)
	{
		ft_error(program, 1);
		return (NULL);
	}
	tmp = program->lex_list;
	while (args)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(program->lex_list, tmp->i);
			tmp = program->lex_list;
		}
		args--;
	}
	return (t_cmd_new(str, program->redir));
}

static void	parse_tokens(t_program *program)
{
	t_cmd	*node;

	del_redirs(program);
	if (program->lex_list->token == PIPE)
		ft_error(program, 2);
		//ft_error(program->lex_list, 2);
	while (program->lex_list)
	{
		if (program->lex_list && program->lex_list->token == PIPE)
			ft_lexerdelone(program->lex_list, program->lex_list->i);
		if (program->lex_list->token == PIPE)
			ft_error(program, 2);
		node = get_cmd(program);
		if (!node)
			return ;
		if (!program->cmd_list)
			program->cmd_list = node;
		else
			ft_cmd_addback(&program->cmd_list, node);
		if (node)
			free(node);
	}
}

bool	ft_parser(t_program	*program )
{
	if (program->lex_list->token == PIPE)
	{
		ft_error(program, 2);
		return (false);
	}
	ft_count_pipes(program);
	parse_tokens(program);
	return (true);
}