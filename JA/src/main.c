/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/23 15:19:27 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int main(int ac, char **av)
{
	int i = 0;
	char *str;
	(void) av;
	t_lexer *lexe;
	lexe = NULL;
	if (ac != 1)
		return (1);
	while(i < 2)
	{
		add_history(str);
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
		//str =">H|'Wdsfs>iiiiiAYUiGHF'";
		lexe = tokenizer(&lexe, str);	
		t_lexer *test = lexe;
		while (test != NULL)
		{
			printf("%s===%u\n", test->str, test->token);
			test = test->next;
		}
		lex_lstclear(&lexe);
		i++;
		free(str);
	}
	return (0);
}

