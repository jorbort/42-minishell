/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:16:05 by jorge             #+#    #+#             */
/*   Updated: 2023/08/26 01:28:52 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*access_path(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->path.env)
	{
		cmd->path.join = ft_strjoin(cmd->path.env[i], "/");
		cmd->path.path = ft_strjoin(cmd->path.join, cmd->cmd[0]);
		free(cmd->path.join);
		if (access(cmd->path.path, F_OK) == 0)
			return (cmd->path.path);
		free(cmd->path.path);
		cmd->path.path = NULL;
		i++;
	}
	return (NULL);
}

char	*find_path(t_cmd *cmd, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		i++;
		if (env[i] == NULL || env[i + 1] == NULL)
			return (ENV_ERROR);
	}
	cmd->path.env = ft_split(env[i] + 5, ':');
	i = 0;
	cmd->path.path = access_path(cmd);
	return (cmd->path.path);
}

t_cmd	*find_cmd(char *argv, char **env, t_files *files)
{
	t_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_cmd), 1);
	cmd->cmd = ft_split(argv, ' ');
	if (cmd->cmd == NULL)
	{
		free_struct(cmd);
		close_exit(COMMAND_ERROR, files);
	}
	if (access(argv, F_OK) == 0)
		cmd->path.path = argv;
	else
		cmd->path.path = find_path(cmd, env);
	if (cmd->path.path == NULL
		|| ft_strncmp(ENV_ERROR, cmd->path.path, 43) == 0)
	{
		free_struct(cmd);
		close_exit(ENV_ERROR, files);
	}
	return (cmd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
