/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/13 17:12:08 by juanantonio      ###   ########.fr       */
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
		//str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
  		str =">Hello|'World>A";
		lexe = tokenizer(&lexe, str);	
		t_lexer *test = lexe;
		while (test != NULL)
		{
			printf("%s===%u\n", test->str,test->token);
			test = test->next;
		}
	}
	return (0);
}

