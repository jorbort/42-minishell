/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/11/20 16:29:42 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	init_program(t_program *program, char **env)
{
	program->data = (t_data *)malloc(sizeof (t_data *));
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
	program = malloc(sizeof(t_program));
	init_program(program, env);
	if (ac != 1)
		return (1);

	while (42)
	{
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $> "RESET_COLOR);
		if (!str | !*str)
			continue ;
		add_history(str);
		program->lex_list = tokenizer(&program->lex_list, str);
		if (!ft_parser(program))
			ft_error(program, 5);
		is_builtin(program);
		change_dir(program, program->cmd_list);
		ft_expand(program);
		free(str);
	}

/*
		//add_history(str);
		str = "$_$_ $HOME";
		program->lex_list = tokenizer(&program->lex_list, str);
		if (!ft_parser(program))
			ft_error(program, 5);
		is_builtin(program);
		ft_expand(program);
*/	
	return (0);
}


