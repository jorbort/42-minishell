/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:45:28 by jorge             #+#    #+#             */
/*   Updated: 2023/08/26 01:29:07 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>

# define FORK_ERROR "Error: fork failed"
# define PIPE_ERROR "Error: pipe failed"
# define ARG_NUM_ERROR "Error: invalid arguments number"
# define PATH_ERROR "Error: path not found"
# define COMMAND_ERROR "Error: command not found"
# define ENV_ERROR "Error: PATH is not an env variable"
# define OPEN_ERROR "Error: file could not be opened"

typedef struct path
{
	char	*path;
	char	*join;
	char	**env;
}	t_path;

typedef struct cmd
{
	t_path	path;
	char	**cmd;
}	t_cmd;

typedef struct files
{
	int		fd[2];
	int		input;
	int		output;
	pid_t	pid;
}	t_files;

//path_bonus.c
char	*access_path(t_cmd *cmd);
char	*find_path(t_cmd *cmd, char **env);
t_cmd	*find_cmd(char *argv, char **env, t_files *files);
void	free_tab(char **tab);
//utils_bonus.c
void	open_errors(t_files *files);
void	free_struct(t_cmd *cmd);
void	close_fd(t_files *files);
void	ft_error(char *error);
void	close_exit(char *error, t_files *files);
#endif