/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/26 09:32:42 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "parser.h"

void	init_program(t_program *program)
{
	program->redir = NULL;
	program->data->nume_redirs = 0;
	program->lex_list = NULL;
	program->cmd_list = NULL;

}


int main(int ac, char **av, char **env)
{
	
	char *str;
	(void) env;
	(void) av;
	t_program *program;
	
	program = malloc(sizeof(t_program));
	init_program(program);
	if (ac != 1)
		return (1);
	while(42)
	{
		add_history(str);
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
		program->lex_list = tokenizer(&program->lex_list, str);	
		if (ft_parser(program) == false)
			ft_error(program, 5);
		t_cmd *test = program->cmd_list;
		t_lexer *test_redir = program->redir; 
		while (test != NULL)
		{
			printf("%s===%u\n", test_redir->str, test_redir->token);
			test = test->next;
		}
		free(str);
	}
	return (0);
}

