/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:32:22 by jbortolo          #+#    #+#             */
/*   Updated: 2023/11/01 18:12:27 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	ft_error(t_program *program, int errno)
{
	(void) program;
	if (errno == 1)
	{
		perror(INVALID_ARG);
		return (false);
	}
	if (errno == 2)
	{
		perror(PIPE_ERROR);
		return (false);
	}
	if (errno == 3)
	{
		perror(TOKEN_ERROR);
		return(false);
	}
	return (true);
}
