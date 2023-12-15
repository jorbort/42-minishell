/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:20:09 by jorge             #+#    #+#             */
/*   Updated: 2023/12/14 18:57:42 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		clean_quotes(split_str[i]);
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}

char	**rejoin_str(char **double_arr)
{
	char	**ret;
	char	*joined_str;

	joined_str = join_split_str(double_arr, NULL);
	free_double_arr(double_arr);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = join_split_str(ret, NULL);
	free_double_arr(ret);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	return (ret);
}

int	cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	return (127);
}

int	check_fd_heredoc(t_program *program, int *end, t_cmd *cmd)
{
	int	fd_in;

	if (program->data->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->here_d_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}
