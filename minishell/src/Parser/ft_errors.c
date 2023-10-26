/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:32:22 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/26 14:57:07 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_error(t_program *program, int errno)
{
	(void) program;
	if (errno == 1)
	{
		perror(INVALID_ARG);
	}
	if (errno == 2)
	{
		perror(PIPE_ERROR);
	}
	if (errno == 3)
	{
		perror(TOKEN_ERROR);
	}
}
