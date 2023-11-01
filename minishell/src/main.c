/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/11/01 18:55:49 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	init_program(t_program *program)
{
	program->data = (t_data*)malloc(sizeof(t_data));
	if (program->data)
	{
		program->data->pipes = 0;
		program->data->nume_redirs = 0;
	}
	program->redir = NULL;
	program->lex_list = NULL;
	program->cmd_list = NULL;
}


int	main(int ac, char **av, char **env)
{
	char		*str;
	t_program	*program;
	t_cmd	*temp;

	(void) env;
	(void) av;
	program = malloc(sizeof(t_program));
	init_program(program);
	if (ac != 1)
		return (1);
	while (42)
	{
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $> "RESET_COLOR);
		add_history(str);
		program->lex_list = tokenizer(&program->lex_list, str);
		if (!ft_parser(program))
			ft_error(program, 5);
		printf("antes del print");
		printf("%s\n", temp->cmd[0]);
		temp = program->cmd_list;
		printf("antes del while \n");
		while (temp != NULL)
		{
			printf("loop");//no llega hasta aqui
			printf("%s\n", temp->cmd[0]);
			temp = temp->next; 
		}
		free(str);
	}
	return (0);
}

