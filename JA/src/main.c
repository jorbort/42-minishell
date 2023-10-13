/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/13 12:01:45 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minishell.h>

int main(int ac, char **av)
{
	
	char *str;
	(void) av;
	t_lexer *lexe;

	lexe = NULL;
	if (ac != 1)
		return (1);
	while(42)
	{
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
  	//	str ="Hello | World";
		lexe = tokenizer(&lexe, str);	
		t_lexer *test = lexe;
		while (test != NULL)
		{
			printf("%s\n", test->str);
			test = test->next;
		}
	}
	return (0);
}

