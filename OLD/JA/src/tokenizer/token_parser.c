/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:55:32 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/26 12:55:30 by juanantonio      ###   ########.fr       */
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
		new = lex_lstnew();
		new->str = ft_strdup(split[j]);
		new->i = j;
		lex_lstadd_back(lexer, new);
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
		if (!strncmp(temp->str, "|", 2))
			temp->token = PIPE;
		else if (!strncmp(temp->str, ">", 2))
			temp->token = GREAT;
		else if (!strncmp(temp->str, ">>", 3))
			temp->token = GREAT_GREAT;
		else if (!strncmp(temp->str, "<", 2))
			temp->token = LESS;
		else if (!strncmp(temp->str, "<<", 3))
			temp->token = LESS_LESS;
		temp = temp->next;
	}
}
