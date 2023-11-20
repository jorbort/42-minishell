/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:16:27 by jbortolo          #+#    #+#             */
/*   Updated: 2023/11/20 15:02:08 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	free_arr(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (str)
		free(str);
	free(arr);
}

void	is_builtin(t_program *program)
{
	char	**builtin_arr;
	t_cmd	*tmp;
	int		len;
	int		i;
	char	*str;

	str = ft_strdup("cd pwd echo export unset env exit");
	builtin_arr = ft_split(str, 32);
	tmp = program->cmd_list;
	while (tmp != NULL)
	{
		len = ft_strlen(tmp->cmd[0]);
		i = 0;
		while (builtin_arr[i] != NULL)
		{
			if (ft_strncmp(tmp->cmd[0], builtin_arr[i], len) == 0)
			{
				tmp->built_in = true;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free_arr(builtin_arr, str);
}

void	exec_builtin(t_program *program)
{
	if (strncmp(program->cmd_list->cmd[0], "cd", 2) == 0)
		change_dir(program, program->cmd_list);
	if (strncmp(program->cmd_list->cmd[0], "pwd", 3) == 0)
		print_wd(program->data);
	if (strncmp(program->cmd_list->cmd[0], "env", 3) == 0)
		print_env(program);
	/*if (strncmp(program->cmd_list->cmd[0], "export", 6) == 0)
		//export();
	if (strncmp(program->cmd_list->cmd[0], "exit", 6) == 0)
		//free_exit();*/
	if (strncmp(program->cmd_list->cmd[0], "echo", 4) == 0)
		ft_echo(program->cmd_list);
	if (strncmp(program->cmd_list->cmd[0], "unset", 6) == 0)
		ft_unset(program, program->cmd_list);
}

