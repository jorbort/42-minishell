/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/29 14:13:11 by jbortolo         ###   ########.fr       */
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

	(void) env;
	(void) av;
	program = malloc(sizeof(t_program));
	init_program(program);
	if (ac != 1)
		return (1);
	while(42)
	{
		add_history(str);
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
		program->lex_list = tokenizer(&program->lex_list, str);
		printf("test 0\n");
		printf("%d \n", ft_parser(program));
		/*if (ft_parser(program) == false)
			ft_error(program, 5);*/
		printf("test1 \n");
		/*printf("%s \n", program->cmd_list->cmd[0]);*/
		free(str);
	}
	return (0);
}

