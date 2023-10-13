/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:55:32 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/13 13:32:14 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_lexer *tokenizer(t_lexer **lexer, char *str)
{
	char **split;
	int j = 0;
	t_lexer *new;

	split = ft_split(str, 32);
	while (split[j])
	{
			new = lex_lstnew();
			new->str = split[j];
			new->i = j;
			lex_lstadd_back(lexer, new);
			j++;
	}
	ft_freesp(split);
	check_readline(lexer);
	check_pipes(lexer);
	return(*lexer);
}

void check_pipes(t_lexer **lexer)
{
	t_lexer *temp;

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

void check_readline(t_lexer **lexer)
{
	t_lexer *temp;
	int len;

	temp = *lexer;
	while (temp != NULL)
	{
		len = strlen(temp->str)
		if (strncmp(temp->str, "|", len))
		
		else if (!strncmp(temp->str, ">", len))
		
		else if (!strncmp(temp->str, ">>", len))
		
		else if (!strncmp(temp->str, "<", len))

		else if (!strncmp(temp->str, "<<", len))
	
			temp = temp->next;
	}
}
