/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:30:21 by jorge             #+#    #+#             */
/*   Updated: 2023/12/12 17:25:06 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_strjoin_export(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	while (s1[i] != 34 || flag == 0)
	{
		if (s1[i] == 34)
			flag = 1;
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '=')
		j++;
	while (s2[j + 1] != '\0')
		str[i++] = s2[j++ + 1];
	str[i] = 34;
	str[i + 1] = '\0';
	return (str);
}


char	*ft_join_env(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '=')
		j++;
	j++;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	export_error(char *c)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	if (c)
	{
		ft_putchar_fd('`', STDERR_FILENO);
		ft_putcleanstr_fd(c, STDERR_FILENO);
		ft_putstr_fd("\': ", STDERR_FILENO);
	}
	ft_putendl_fd("not a valid identifier", STDERR_FILENO);
	return (1);
}

void	print_export(t_program *program, char **export)
{
	int	i;

	i = 0;
	if (!export || !*export)
		print_env(program);
	else
	{
		while (export[i])
		{
			ft_printf("declare -x %s\n", export[i]);
			i++;
		}
	}
}

int	ft_export_cmp(char *export, char *str)
{
	int	i;

	i = 0;
	while (export[i] != '=' && str[i] != '\0')
	{
		if (export[i] != str[i])
			return (export[i] - str[i]);
		i++;
	}
	if (export[i] == '=' && str[i] == '\0')
		return (0);
	return (export[i] - str[i]);
}
