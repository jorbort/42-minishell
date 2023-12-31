/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:38:48 by jorge             #+#    #+#             */
/*   Updated: 2024/01/03 18:38:12 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	*t_cmd_new(char **str_cmd, int num_redirs, t_lexer *redirection)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	new->cmd = str_cmd;
	new->built_in = false;
	new->num_redirs = num_redirs;
	new->redirection = redirection;
	new->here_d_file_name = NULL;
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

void	cmd_clear(t_cmd **list)
{
	t_cmd	*tmp;
	t_lexer	*redir_temp;

	if (!list || !(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		redir_temp = (*list)->redirection;
		if (redir_temp)
			ft_lexclear(&redir_temp);
		if ((*list)->cmd)
			free_double_arr((*list)->cmd);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

t_cmd	*ft_first(t_cmd *cmd_list)
{
	if (!cmd_list)
		return (NULL);
	while (cmd_list->prev)
	{
		cmd_list = cmd_list->prev;
	}
	return (cmd_list);
}
