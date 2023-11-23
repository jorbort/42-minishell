/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:38:10 by jorge             #+#    #+#             */
/*   Updated: 2023/11/23 17:37:50 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	free_program(t_program *program)
{
	free_double_arr(program->data->envp);
	cmd_clear(&program->cmd_list);
	free(program->data->pwd);
	free(program->data->prev_pwd);
}


static bool	is_numeric(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	calc_exit_code(char **str)
{
	int	exitnro;

	if (!str[1])
		exitnro = 0;
	else if (is_numeric(str[1]))
		exitnro = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exitnro = 255;
	}
	free_arr(str);
	exit(exitnro);
}


void	ft_exit(t_program *program,t_cmd  *cmd_list)
{
	char	**temp;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (cmd_list->cmd[1] && cmd_list->cmd[2])
	{
		ft_putstr_fd("minishell: exit: Too many arguments\n", STDERR_FILENO);
		return (false);
	}
	temp = ft_arrdup(cmd_list->cmd);
	free_program(program);
	calc_exit_code(temp);
	return (true);
}