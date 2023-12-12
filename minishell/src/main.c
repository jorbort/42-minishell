/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/12 12:20:29 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	init_program(t_program *program, char **env, int *excode)
{
	program->data = (t_data *)malloc(sizeof (t_data));
	if (program->data)
	{
		program->data->pipes = 0;
		program->data->nume_redirs = 0;
		program->data->envp = ft_arrdup(env);
		parse_env(program, program->data);
		find_pwd(program->data);
		program->data->export = malloc(sizeof(char *));
		if (program->data->export)
			program->data->export[0] = NULL;
	}
	program->redir = NULL;
	program->lex_list = NULL;
	program->cmd_list = NULL;
	program->exit_code = excode;
}

void	shell_loop(t_program *program)
{
	char		*str;

	while (42)
	{
		str = readline(BLUE_T"MiniShell:" YELLOW_T" $> "RESET_COLOR);
		if (!str || !*str)
		{
			if (isatty(STDIN_FILENO))
				write(2, "exit\n", 6);
			exit ((*program->exit_code));
		}
		add_history(str);
		program->lex_list = tokenizer(&program->lex_list, str);
		if (ft_parser(program))
			handle_execution(program);
		//printf("%s\n", program->data->prev_pwd);
		//printf("%s\n",program->data->pwd);
		//free_program(program);
		//free(program->lex_list);
		//init_program(program, program->data->envp, (program->exit_code));
		free(str);
	}
}

int	main(int ac, char **av, char **env)
{
	t_program	*program;
	static int	excode = 0;

	(void) av;
	program = malloc(sizeof(t_program));
	init_program(program, env, &excode);
	if (ac != 1)
		return (1);
	rl_catch_signals = 0;
	init_signals(1);
	shell_loop(program);
	return (0);
}
