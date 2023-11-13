/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:19:59 by jorge             #+#    #+#             */
/*   Updated: 2023/11/13 16:33:29 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	init_parser(t_lexer *lex_list, t_program *program)
{
	t_parser	pars;

	pars.lexer_list = lex_list;
	pars.redirections = NULL;
	pars.num_redirections = 0;
	pars.program = program;
	return (pars);
}

void	ft_count_pipes(t_lexer *lex_list, t_program *program)
{
	t_lexer	*tmp;

	tmp = lex_list;
	program->data->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			program->data->pipes++;
		tmp = tmp->next;
	}
}

int	count_args(t_lexer *lex_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lex_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
