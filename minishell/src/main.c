/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/11/08 17:15:07 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	init_program(t_program *program, char **env)
{
	program->data = (t_data*) malloc( sizeof(t_data *));
	if (program->data)
	{
		program->data->pipes = 0;
		program->data->nume_redirs = 0;
		program->data->pwd = getcwd(NULL, sizeof(NULL));
		program->data->prev_pwd = NULL;
		program->data->envp = ft_arrdup(env);
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
	str = "cd | pwd";
	program = malloc(sizeof(t_program));
	init_program(program, env);
	if (ac != 1)
		return (1);
	while (42)
	{
		//str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $> "RESET_COLOR);
		add_history(str);
		program->lex_list = tokenizer(&program->lex_list, str);
		if (!ft_parser(program))
			ft_error(program, 5);
		is_builtin(program);
		//free(str);
	}
	return (0);
}
