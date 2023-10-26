/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:32:22 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/26 09:06:04 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
