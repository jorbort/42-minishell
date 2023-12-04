/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:12:21 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/04 10:49:45 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	ft_heredoc(t_program *program)
{
	char	*str;
	char	*eof;
	int		fd;

	fd = open("/tmp/herdoc.txt", O_RDWR | O_APPEND | O_CREAT, 0666);
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
