/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/11/29 13:47:28 by juanantonio      ###   ########.fr       */
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
		program->data->pwd = getcwd(NULL, MAXPATHLEN);
		program->data->prev_pwd = NULL;
		program->data->envp = ft_arrdup(env);

	}
	program->redir = NULL;
	program->lex_list = NULL;
	program->cmd_list = NULL;
	program->exit_code = excode;
}


int	main(int ac, char **av, char **env)
{
	char		*str;
	t_program	*program;
	static int	excode = 0;

	(void) env;
	(void) av;
	program = malloc(sizeof(t_program));
	init_program(program, env, &excode);
	if (ac != 1)
		return (1);
	while (42)
	{
		program = malloc(sizeof(t_program));
		init_program(program, env, &excode);
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $> "RESET_COLOR);
		if (!str | !*str)
			continue ;
		add_history(str);
		program->lex_list = tokenizer(&program->lex_list, str);
		if (!ft_parser(program))
			ft_error(program, 5);
		is_builtin(program);
		exec_builtin(program);
		ft_expand(program);
		printf("numero exit main = %d\n", excode);
		printf("numero exit struct= %d\n", (*program->exit_code));

		free_program(program);
		free(program);
		free(str);
	
	}
	return (0);
}
