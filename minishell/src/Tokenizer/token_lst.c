/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:39:08 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/13 11:59:28 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

t_lexer	*lex_lstnew(void)
{
	t_lexer	*node;

	node = malloc(sizeof(t_lexer));
	if (!node)
		return (NULL);
	node->str = NULL;
	node->token = NONE;
	node->i = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	lex_lstadd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*last;

	if ((*lst))
	{
		last = lex_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
		(*lst) = new;
}

void	lex_lstclear(t_lexer **lst)
{
	t_lexer	*nxt;
	t_lexer	*aux;

	aux = *lst;
	while (aux)
	{
		nxt = aux->next;
		free(aux->str);
		free(aux);
		aux = nxt;
	}
	*lst = NULL;
}

int	lex_lstsize(t_lexer *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lexer	*lex_lstlast(t_lexer *lst)
{
	t_lexer	*node;

	if (!lst)
		return (0);
	node = lst;
	while ((node->next))
		node = node->next;
	return (node);
}
