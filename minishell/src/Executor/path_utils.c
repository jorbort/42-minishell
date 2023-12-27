/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:04:17 by jbortolo          #+#    #+#             */
/*   Updated: 2023/12/27 15:15:05 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	*search_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (0);
}

int	parse_env(t_program *program, t_data *data)
{
	char	*path_fromenv;
	int		i;
	char	*tmp;

	path_fromenv = search_path(program->data->envp);
	data->paths = ft_split(path_fromenv, ':');
	free(path_fromenv);
	i = 0;
	while (data->paths[i])
	{
		if (ft_strncmp(&data->paths[i][ft_strlen(data->paths[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(data->paths[i], "/");
			free(data->paths[i]);
			data->paths[i] = tmp;
		}
		i++;
	}
	return (0);
}
