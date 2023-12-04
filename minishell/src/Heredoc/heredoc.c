/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:12:21 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/04 12:22:34 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	ft_heredoc(t_program *program)
{
	char		*hdoc;
	static int	i;

	i = -1;
	hdoc = ft_strjoin("/tmp/herdoc_", ft_itoa(++i));
	hdoc = ft_strjoin_free(hdoc, ".txt");
	program->cmd_list->here_d_file_name = hdoc;
	ft_fill_heredoc(program);
}

void	ft_fill_heredoc(t_program *program)
{
	char	*str;
	char	*eof;
	int		fd;
	char	*path;

	path = program->cmd_list->here_d_file_name;
	fd = open(path, O_RDWR | O_APPEND | O_CREAT, 0666);
	eof = ft_strjoin(program->cmd_list->redirection->str, "\n");
	str = ft_strjoin(readline(" >"), "\n");
	while (str && ft_strncmp(str, eof, ft_strlen(str)) != 0)
	{
		ft_putstr_fd(str, fd);
		free(str);
		str = readline(" >");
		str = ft_strjoin_free(str, "\n");
	}
	close(fd);
	free(str);
}

int	set_heredoc(t_program *program, t_cmd *cmd_list)
{
	t_lexer	*start;

	start = cmd_list->redirection;
	while (cmd_list->redirection)
	{
		if (cmd_list->redirection->token == LESS_LESS)
		{
			if (cmd_list->here_d_file_name)
				free(cmd_list->here_d_file_name);
			ft_heredoc(program);
		}
		cmd_list->redirection = cmd_list->redirection->next;
	}
	cmd_list->redirection = start;
	return (0);
}
