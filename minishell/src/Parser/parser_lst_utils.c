/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:38:48 by jorge             #+#    #+#             */
/*   Updated: 2023/11/01 18:47:15 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	*t_cmd_new(char **str_cmd,int num_redirs, t_lexer *redirection)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	new->cmd = str_cmd;
	new->built_in = false;
	new->num_redirs = num_redirs;
	new->redirection = redirection;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_cmd_addback(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	ft_lexeradd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
