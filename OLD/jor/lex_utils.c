/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:50:39 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/23 15:10:58 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_lexerdelone(t_lexer *lex_list, int to_del)
{
	t_lexer	*node;
	t_lexer	*prev;
	t_lexer	*start;

	start = lex_list;
	node = start;
	if (lex_list->i == to_del)
	{
		ft_lexerdel_first(lex_list);
		return ;
	}
	while (node && node->i != to_del)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	ft_lexclear_one(node);
	lex_list = start;
}

t_lexer	ft_lexclear_one(t_lexer *lex_list)
{
	if (lex_list->str)
	{
		free(lex_list->str);
		lex_list->str = NULL;
	}
	free(lex_list);
	lex_list = NULL;
	return ;
}

void	ft_lexerdel_first(t_lexer *lex_list)
{
	t_lexer	*node;

	node = lex_list;
	lex_list = node->next;
	ft_lexclear_one(node);
	if (lex_list)
		lex_list->prev = NULL;
}

void	ft_lexclear(t_lexer *lex_list)
{
	t_lexer	*tmp;

	if (!lex_list)
		return ;
	while (lex_list)
	{
		tmp = (*lex_list).next;
		if ((*lex_list).str)
			free((*lex_list).str);
		free(lex_list);
		lex_list = tmp;
	}
	lex_list = NULL;
}