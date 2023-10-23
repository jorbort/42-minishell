/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/10/23 13:19:17 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_parser(t_program	*program )
{
	if (program->lex_list->token == PIPE)
		ft_error(program, 2);
	count_pipes(program);
	parse_tokens(program);
}

void	get_redir(t_program *program, t_lexer *tmp)
{
	t_lexer	*node;
	int		index_a;
	int		index_b;

	tmp = program->lex_list;
	node = ft_lex_new(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		ft_error(program, 1);
	ft_lexeradd_back(program->redir, node);
	index_a = tmp->i;
	index_b = tmp->next->i;
	ft_lexerdelone(program->lex_list, index_a);
	ft_lexerdelone(program->lex_list, index_b);
	program->data->nume_redirs++;
	free(node);
}

void	del_redirs(t_program *program)
{
	t_lexer	*tmp;

	tmp = program->lex_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		ft_error(program, 1);
	if (tmp->next->token)
		ft_error(program, 3);
	if ((tmp->token >= GREAT && tmp->token <= LESS_LESS))
		get_redir(program, tmp);
	del_redirs(program);
}

t_cmd	*get_cmd(t_program *program)
{
	char	**str;
	int		i;
	t_lexer	*tmp;
	int		args;

	i = 0;
	args = count_args(program);
	str = ft_calloc(args + 1, sizeof(char *));
	if (!str)
		ft_error(program, 1);//to-do
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

void	parse_tokens(t_program *program)
{
	t_cmd	*node;

	program->data->pipes = count_pipes();//to-do funcion que cuente los pipes para saber el numero de comandos 	
	del_redir(program);
	if (program->lex_list->token == PIPE)
		ft_error(program->lex_list, 2);
	while (program->lex_list)
	{
		if (program->lex_list && program->lex_list->token == PIPE)
			ft_lexerdelone(program->lex_list, program->lex_list->i);
		if (program->lex_list->token == PIPE)
			ft_error(program, 2);
		node = get_cmd(program);
		if (!node)
			ft_error(program, 1);
		if (!program->cmd_list)
			program->cmd_list = node;
		else
			ft_cmd_addback(program->cmd_list, node);
		free(node);
	}
}
