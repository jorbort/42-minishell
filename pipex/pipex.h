/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:17:29 by jorge             #+#    #+#             */
/*   Updated: 2023/08/27 15:59:30 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	pid_t	pid1;
	pid_t	pid2;
}	t_files;

//pipex.c
void	free_tab(char **tab);
void	ft_error(char *error);
void	close_fd(t_files *files);
void	open_files(t_files *files, char **argv);
void	free_struct(t_cmd *cmd);
#endif