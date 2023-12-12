/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:31:38 by jorge             #+#    #+#             */
/*   Updated: 2023/12/12 13:02:11 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	add_redir(t_lexer *tmp, t_parser *pars)
{
	t_lexer	*node;
	int		index_a;
	int		index_b;

	node = ft_lex_new(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		ft_error(pars->program, 3);
	ft_lexeradd_back(&pars->redirections, node);
	index_a = tmp->i;
	index_b = tmp->next->i;
	ft_lexerdelone(&pars->lexer_list, index_a);
	ft_lexerdelone(&pars->lexer_list, index_b);
	pars->num_redirections++;
	return (0);
}

void	del_redirs(t_parser *pars)
{
	t_lexer	*tmp;

	tmp = pars->lexer_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		ft_error (pars->program, 3);
	if (tmp->next->token)
		ft_error(pars->program, 4);
	if (tmp->token >= GREAT && tmp->token <= LESS_LESS)
		add_redir(tmp, pars);
	del_redirs(pars);
}
