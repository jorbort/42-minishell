/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:44:41 by jbortolo          #+#    #+#             */
/*   Updated: 2023/12/11 10:11:22 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**add_export_var(char *str, char **export)
{
	char	**tmp;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	tmp = malloc(sizeof(char *) * (ft_arr_len(export) + 2));
	if (!tmp)
		return (NULL);
	while (export[i])
	{
		if (ft_env_cmp(export[i], str) == 0)
		{
			tmp[i] = ft_export_dup(str);
			flag = 1;
		}
		else
			tmp[i] = ft_strdup(export[i]);
		i++;
	}
	if (flag == 0)
		tmp[i++] = ft_export_dup(str);
	tmp[i] = NULL;
	free_double_arr(export);
	return (tmp);
}

void	append_env(char *str, t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '+' || flag == 1)
		{
			flag = 1;
			str[i] = str[i + 1];
		}
		i++;
	}
	str[i] = '\0';
	data->envp = ft_join_envp(str, data->envp);
	data->export = ft_join_export(str, data->export);
}

void	add_env(char *str, t_data *data)
{
	data->envp = add_to_env(str, data->envp);
	data->export = add_export_var(str, data->export);
}

int	export_format(char *str)
{
	int	i;

	i = 0;
	while ((ft_isalpha(str[i]) == 1 || str[i] == '_') && str[i])
		i++;
	if (ft_strncmp(&str[i], "+=", 2) == 0 && i != 0)
		return (3);
	if (str[i] == '\0')
		return (2);
	if (str[i] != '=' || i == 0)
		return (1);
	return (0);
}

int	ft_export(t_cmd *cmd_list, t_program *program)
{
	int		i;
	int		exit;

	i = 0;
	exit = 0;
	if (!cmd_list->cmd[1] || cmd_list->cmd[1][0] == '\0')
		print_export(program, program->data->export);
	else
	{
		while (cmd_list->cmd[++i])
		{
			if (cmd_list->cmd[i])
				clean_quotes(cmd_list->cmd[i]);
			if (export_format(cmd_list->cmd[i]) == 0)
				add_env(cmd_list->cmd[i], program->data);
			else if (export_format(cmd_list->cmd[i]) == 3)
				append_env(cmd_list->cmd[i], program->data);
			else if (export_format(cmd_list->cmd[i]) == 2)
				program->data->export = add_export_var
					(cmd_list->cmd[i], program->data->export);
			else
				exit = export_error(cmd_list->cmd[i]);
		}
	}
	return (exit);
}
