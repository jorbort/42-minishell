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
	t_lexer	*t;

	t = *lexer;
	while (t != NULL)
	{
		if (!ft_strncmp(t->str, "|", 2))
			t->token = PIPE;
		else if (!ft_strncmp(t->str, ">", 2))
			t->token = GREAT;
		else if (!ft_strncmp(t->str, ">>", 3))
			t->token = GREAT_GREAT;
		else if (!ft_strncmp(t->str, "<", 2))
			t->token = LESS;
		else if (!ft_strncmp(t->str, "<<", 3))
			t->token = LESS_LESS;
		else if (!ft_strncmp(t->str, "<<<", 3) || !strncmp(t->str, ">>>", 3))
			t->token = ERROR;
		else if (!ft_strncmp(t->str, "||", 2))
			t->token = ERROR;
		else if (ft_strchr(t->str, '>') && ft_strchr(t->str, '<'))
			t->token = ERROR;
		else
			t->token = 0;
		t = t->next;
	}
}
