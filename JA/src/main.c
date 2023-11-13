/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/11/13 12:42:44 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int main(int ac, char **av)
{
	
	char *str;
	(void) av;
	t_lexer *lexe = NULL;
	if (ac != 1)
		return (1);
	str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);

	while(42)
	{
		//add_history(str);
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
		lexe = tokenizer(&lexe, str);	
		t_lexer *test = lexe;
		while (test != NULL)
		{
			printf("%s===%u\n", test->str, test->token);
			test = test->next;
		}
		lex_lstclear(&lexe);
	}
	return (0);
}

