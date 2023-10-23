/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:32:22 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/23 15:11:45 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_error(t_program *program, int errno)
{
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
