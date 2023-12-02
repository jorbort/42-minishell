/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:40:47 by jorge             #+#    #+#             */
/*   Updated: 2023/12/02 17:07:41 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	check_append_outfile(t_lexer *redirection)
{
	int	fd;

	if (redirection->token == GREAT_GREAT)
		fd = open(redirection->str, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirection->str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	handle_infile(char	*file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: infile: No such file or directory\n",
				STDERR_FILENO);
		return (1);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe Error \n", STDERR_FILENO);
		return (1);
	}
	if (fd > 0)
		close(fd);
	return (0);
}

int	handle_outfile(t_lexer *redirection)
{
	int	fd;

	fd = check_append_outfile(redirection);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n",STDERR_FILENO);
		return (1);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe eror\n", STDERR_FILENO);
		return (1);
	}
	if (fd > 0)
		close(fd);
	return (0);
}


int	check_redirs(t_cmd *cmd_list)
{
	t_lexer	*start;

	start = cmd_list->redirection;
	while (cmd_list->redirection)
	{
		if (cmd_list->redirection->token == LESS)
		{
			if (handle_infile(cmd_list->redirection->str))
				return (1);
		}
		else if (cmd_list->redirection->token == GREAT
				|| cmd_list->redirection->token == GREAT_GREAT)
		{
			if (handle_outfile(cmd_list->redirection))
				return (1);
		}
		else if (cmd_list->redirection->token == LESS_LESS)
		{
			if (handle_infile(cmd_list->here_d_file_name))
				return (1);
		}
		cmd_list->redirection = cmd_list->redirection->next;
	}
	cmd_list->redirection = start;
	return (0);
}