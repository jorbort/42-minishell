/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:43:49 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/27 11:31:32 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

static void	sig_handler_def(int signum)
{
	if (signum == CTRL_C)
	{
		ft_printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	sig_handler_childs(int signum)
{
	if (signum == CTRL_C)
		ft_printf("\n");
}

int	init_signals(int mode)
{
	if (mode == 1)
		signal(CTRL_C, sig_handler_def);
	else if (mode == 0)
		signal(CTRL_C, sig_handler_childs);
	signal(CTRL_SLASH, sig_handler_def);
	return (1);
}
