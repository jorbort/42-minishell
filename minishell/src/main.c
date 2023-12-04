/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/04 19:18:51 by jorge            ###   ########.fr       */
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
		if (!str | !*str)
			continue ;
		add_history(str);
		program->lex_list = tokenizer(&program->lex_list, str);
		if (!ft_parser(program))
			ft_error(program, 5);
		handle_execution(program);
		printf("%s\n", program->data->prev_pwd);
		printf("%s\n",program->data->pwd);
		// free_program(program);
		// free(program);
		// free(str);
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
	shell_loop(program);
	return (0);
}
