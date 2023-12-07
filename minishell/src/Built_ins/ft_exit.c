/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:38:10 by jorge             #+#    #+#             */
/*   Updated: 2023/12/07 09:57:56 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while ((str[i] != '\0' || str1[i] != '\0'))
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (0);
}

static int	ft_issspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_test_int(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	i = ft_issspace(str);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result * sign > (LLONG_MAX - (str[i] - '0')) / 10 || result
			* sign < (LLONG_MIN + (str[i] - '0')) / 10)
			return (-1);
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && ft_issspace(str + i) == 0)
		return (-1);
	return (0);
}

int	ft_exit(char **cmd_arr, t_program *program)
{
	if (cmd_arr[1] && ft_strcmp(cmd_arr[1], "--") == 0)
	{
		exit ((*program->exit_code));
	}
	else if (cmd_arr[1] && ft_test_int(cmd_arr[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmd_arr[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	else if (cmd_arr[1])
	{
		if (cmd_arr[2])
		{
			ft_putstr_fd("minishell: exit: Too many arguments\n", STDERR_FILENO);
			return (1);
		}
		exit(ft_atoi(cmd_arr[1]));
	}
	exit((*program->exit_code));
}
