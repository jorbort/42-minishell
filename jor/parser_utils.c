/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:38:48 by jorge             #+#    #+#             */
/*   Updated: 2023/10/23 15:10:34 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*t_cmd_new(char **str, char *redirection)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	new->cmd = str;
	new->built_in = false;
	new->redirection = redirection;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_cmd_addback(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	temp = *lst;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	ft_cmd_rmfirst(t_cmd **lst)
{
	t_cmd	*temp;

	if (!*lst)
		return ;
	temp = (*lst)->next;
	ft_lexer_rm(&(*lst)->redirection);
	free(*lst);
	*lst = temp;
}

int	count_args(t_program *program)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = program->lex_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_count_pipes(t_program *program)
{
	t_lexer	*tmp;

	tmp = program->lex_list;
	while (tmp)
	{
		if (tmp->token == PIPE)
			program->data->pipes++;
		tmp = tmp->next;
	}
}
