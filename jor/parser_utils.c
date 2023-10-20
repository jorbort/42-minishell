/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:38:48 by jorge             #+#    #+#             */
/*   Updated: 2023/10/19 19:06:51 by jorge            ###   ########.fr       */
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
