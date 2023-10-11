/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:55:32 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/11 14:07:54 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

t_lexer *tokenizer(t_lexer **lexer, char *str)
{
	char **split;
	int j = -1;
	t_lexer *new;

	split = ft_split(str, 32);
/*	while(split[i])
		i++;
	//printf("%i\n", i);
	lexer = malloc(i * sizeof(t_lexer));
	while (split[j++])
	{
		lexer[j].str = split[j];
		//printf("%s\n", lexer[j].str);
	}
*/
	while (split[j++])
	{
			new = lex_lstnew();
			new->str = split[j];
			lex_lstadd_back(lexer, new);
	}
	return(lexer);
}
