/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:38:10 by jorge             #+#    #+#             */
/*   Updated: 2023/11/27 21:36:23 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static long long	ft_exit_atoi(char *str, int *exitnro)
{
	int			i;
	int			flag;
	long long	n;

	n = 0;
	flag = 1;
	i = 0;
	if (strlen(str) == 19 &&
		(ft_strncmp("9223372036854775807", str, 20) < 0))
		return (*exitnro = -1);
	if ((ft_strlen(str) == 20 && ft_strncmp
			("-9223372036854775807", str, 21) < 0) || ft_strlen(str) > 20)
		return (*exitnro = -1);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * flag);
}


void	free_program(t_program *program)
{
	if (program->data->envp)
		free_double_arr(program->data->envp);
	if (program->cmd_list)
		cmd_clear(&program->cmd_list);
	if (program->data->pwd)
		free(program->data->pwd);
	if (program->data->prev_pwd)
		free(program->data->prev_pwd);
	if (program->data)
		free(program->data);
}


static bool	is_numeric(char *str)
{
	int	i;

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
	long long	n;
	int			exitnro;

	exitnro = 0;
	if (!str[1])
		n = 0;
	else if (is_numeric(str[1]))
		n = ft_exit_atoi(str[1], &exitnro);
	if (exitnro == -1)
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		n = 255;
	}
	free_double_arr(str);
	exit(n);
}

bool	ft_exit(t_program *program, t_cmd *cmd_list)
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
