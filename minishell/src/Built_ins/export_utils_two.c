/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:55:16 by jorgebortol       #+#    #+#             */
/*   Updated: 2023/12/10 17:21:42 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char **add_to_env(char *str, char **envp)
{
	char 	**tmp;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	tmp = malloc(sizeof(char *) * (ft_arr_len(envp) + 2));
	if (!tmp)
		return(NULL);
	while (envp[i])
	{
		if (ft_env_cmp(envp[i],str) == 0)
		{
			tmp[i] = ft_strdup(str);
			flag = 1;
		}
		else
			tmp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (flag == 0)
		tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	free_double_arr(envp);
	return (tmp);
}

int	ft_env_cmp(char *exp, char *str)
{
	int	i;

	i = 0;
	while (exp[i] != '=' || str[i] != '\0') 
	{
		if (exp[i] != str[i])
			return (exp[i] - str[i]);
		i++;
	}
	if (exp[i] == '=' && str[i] == '\0')
		return (0);
	return (exp[i] - str[i]);
}

char	**ft_join_envp(char  *str, char **envp)
{
	char 	**tmp;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	tmp = malloc(sizeof(char *) * (ft_arr_len(envp) + 2));
	if (!tmp)
		return (NULL);
	while (envp[i])
	{
		if (ft_env_cmp(envp[i], str) == 0)
		{
			tmp[i] = ft_join_env(envp[i],str);
			flag = 1;
		}
		else
			tmp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (flag == 0)
		tmp[i++] = ft_strdup_join(str);//to-do
	tmp[i] = NULL;
	free_double_arr(envp);
	return (tmp);
}

char	**ft_join_export(char *str, char **export)
{
	char 	**tmp;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	tmp = malloc(sizeof(char *) * (ft_arr_len(export) + 2));
	if (!tmp)
		return (NULL);
	while (export[i])
	{
		if (ft_export_cmp(export[i], str) == 0)
		{
			tmp[i] = ft_strjoin_export(export[i], str);
			flag = 1;
		}
		else
			tmp[i] = ft_strdup(export[i]);
		i++; 
	}
	if (flag == 0)
	tmp[i++] = ft_export_dup(str);
	tmp[i] = NULL;
	free_double_arr(export);
	return (tmp);
}