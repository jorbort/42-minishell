/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:55:32 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/23 17:40:26 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_lexer	*tokenizer(t_lexer **lexer, char *str)
{
	char	**split;
	t_lexer	*new;
	int		j;

	j = 0;
	split = ft_pipesplit(str);
	while (split[j])
	{
		if (ft_strncmp(split[j], "\"\"", 3))
		{
			new = lex_lstnew();
			new->str = ft_strdup(split[j]);
			new->i = j;
			lex_lstadd_back(lexer, new);
		}
		j++;
	}
	ft_freesp(split);
	check_pipes(lexer);
	return (*lexer);
}

void	check_pipes(t_lexer **lexer)
{
	t_lexer	*temp;

	temp = *lexer;
	while (temp != NULL)
	{
		if (!ft_strncmp(temp->str, "|", 2))
			temp->token = PIPE;
		else if (!ft_strncmp(temp->str, ">", 2))
			temp->token = GREAT;
		else if (!ft_strncmp(temp->str, ">>", 3))
			temp->token = GREAT_GREAT;
		else if (!ft_strncmp(temp->str, "<", 2))
			temp->token = LESS;
		else if (!ft_strncmp(temp->str, "<<", 3))
			temp->token = LESS_LESS;
		else if (!ft_strncmp(temp->str, "<<<", 3) || !strncmp(temp->str, ">>>", 3))
			temp->token = ERROR;
		else if (!ft_strncmp(temp->str, "||", 2))
			temp->token = ERROR;
		else if (ft_strchr(temp->str, '>') && ft_strchr(temp->str, '<'))
			temp->token = ERROR;
		else
			temp->token = 0;
		temp = temp->next;
	}
}
