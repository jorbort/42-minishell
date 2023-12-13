/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/13 08:30:31 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	reset_program(t_program *program, char *str)
{
	cmd_clear(&program->cmd_list);
	free(str);
	if (program->data->pid)
		free(program->data->pid);
	free_double_arr(program->data->paths);
}

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
		free(str);
		//reset_program(program, str); no funciona bien
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
