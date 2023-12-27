/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:32:22 by jbortolo          #+#    #+#             */
/*   Updated: 2023/12/27 15:14:17 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	ft_error(t_program *program, int errno)
{
	(void) program;
	(*program->exit_code) = 2;
	ft_lexclear(&program->lex_list);
	if (errno == PIPE)
	{
		ft_putstr_fd(MSHELL, STDERR_FILENO);
		ft_putstr_fd(MSSG_ERR_PIPE, STDERR_FILENO);
		return (false);
	}
	if (errno == GREAT)
	{
		ft_putstr_fd(MSHELL, STDERR_FILENO);
		ft_putstr_fd(MSSG_ERR_GREAT, STDERR_FILENO);
		return (false);
	}
	if (errno == GREAT_GREAT)
	{
		ft_putstr_fd(MSHELL, STDERR_FILENO);
		ft_putstr_fd(MSSG_ERR_GREAT_GREAT, STDERR_FILENO);
		return (false);
	}
	return (ft_error2(program, errno));
}

bool	ft_error2(t_program *program, int errno)
{
	(void) program;
	if (errno == LESS)
	{
		ft_putstr_fd(MSHELL, STDERR_FILENO);
		ft_putstr_fd(MSSG_ERR_LESS, STDERR_FILENO);
		return (false);
	}
	if (errno == LESS_LESS)
	{
		ft_putstr_fd(MSHELL, STDERR_FILENO);
		ft_putstr_fd(MSSG_ERR_LESS_LESS, STDERR_FILENO);
		return (false);
	}
	if (errno == 0)
	{
		ft_putstr_fd(MSHELL, STDERR_FILENO);
		ft_putstr_fd(MSSG_ERR_NL, STDERR_FILENO);
		return (false);
	}
	return (false);
}
