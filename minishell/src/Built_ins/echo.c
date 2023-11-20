/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:46:49 by jorge             #+#    #+#             */
/*   Updated: 2023/11/20 14:47:12 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	print_cmd(int i, char **str, int fd)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], fd);
		if (str[i])
			ft_putchar_fd(' ', fd);
	}
}

bool	ft_echo(t_cmd *cmd_list)
{
	int		i;
	int		j;
	bool	n_flag;

	i = 1;
	n_flag = false;
	while (cmd_list->cmd[i] && cmd_list->cmd[i][0] == '-' &&
			cmd_list->cmd[i][1] == 'n')
	{
		j = 1;
		while (cmd_list->cmd[i][j] == 'n')
			j++;
		if (cmd_list->cmd[i][j] == '\0')
			n_flag = true;
		else
			break ;
		i++;
	}
	print_cmd(i, cmd_list->cmd, STDOUT_FILENO);
	if (!n_flag)
		ft_putchar_fd('n', STDOUT_FILENO);
	return (true);
}
