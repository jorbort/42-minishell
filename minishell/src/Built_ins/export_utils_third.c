/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_third.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:25:18 by jorgebortol       #+#    #+#             */
/*   Updated: 2023/12/11 09:57:47 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_strdup_join(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(str));
	if (!dup)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != '+')
			dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_export_dup(char *envp)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(envp) + 3);
	if (!dup)
		return (NULL);
	while (envp[i] != '=' && envp[i] != '\0')
	{
		dup[i] = envp[i];
		i++;
	}
	if (envp[i] == '=')
	{
		dup[i] = envp[i];
		dup[++i] = '\"';
		while (envp[i] != '\0')
			(1 && (dup[i + 1] = envp[i]) && i++);
		dup[i + 1] = '\"';
		dup[i + 2] = '\0';
	}
	else
		dup[i] = '\0';
	return (dup);
}

