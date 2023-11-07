/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:35:22 by jbortolo          #+#    #+#             */
/*   Updated: 2023/11/07 17:12:55 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	print_wd(t_data *data)
{
	ft_putstr_fd(data->pwd, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
