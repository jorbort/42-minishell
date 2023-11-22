/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:45 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/22 12:04:12 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void	ft_expand(t_program *program)
{
	int	i;

	i = -1;
	while (program->cmd_list->cmd[++i] != NULL)
	{
		printf("%s\n", program->cmd_list->cmd[i]);
		if (ft_strchr(program->cmd_list->cmd[i], '$') != NULL)
			ft_expand_var(program, i);
		printf("%s\n", program->cmd_list->cmd[i]);
	}
}

void	ft_expand_var(t_program *program, int i)
{
	char	*str;
	char	*cmd;
	char	*var_name;
	int		c;
	int		exp_flag;
	int		var_len;
	char	*exp_var;
	char	*(*sj)(char *, char *);

	sj = &ft_strjoin_doublefree;
	str = ft_strdup(program->cmd_list->cmd[i]);
	ft_freegnl(&program->cmd_list->cmd[i]);
	cmd = program->cmd_list->cmd[i];
	exp_flag = ft_search_quote(str);
	c = -1;
	while (str[++c])
	{
		if (str[c] == '$')
		{
			var_name = ft_get_varname(str, c + 1);
			var_len = ft_strlen(var_name);
			if (exp_var != NULL && exp_flag && var_len != 0)
			{
				exp_var = get_myenv(program, var_name);
				cmd = ft_strjoin_free(cmd, exp_var);
			}
			else if (!exp_flag && var_len != 0)
				cmd = sj(cmd, ft_substr(str, c, var_len + 1));
			if (var_len != 0)
				c += var_len;
			else
				cmd = sj(cmd, ft_substr(str, c, 1));
		}
		else
			cmd = sj(cmd, ft_substr(str, c, 1));
	}
	program->cmd_list->cmd[i] = cmd;
}

int	ft_search_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			return (1);
		if (str[i] == '\'')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_varname(char *str, int i)
{
	int		j;

	j = 0;
	while ((str[i + j] && ft_isalnum(str[i + j])) || str[i + j] == '_' 
		|| str[i + j] == '?')
		j++;
	return (ft_substr(str, i, j));
}

///implementacion funcion getenv en programa con la copia de env** 
char	*get_myenv(t_program *program, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	var = ft_strjoin_free(var, "=");
	printf ("%s\n", var);
	while (program->data->envp[i])
	{
		if (!ft_strncmp(program->data->envp[i], var, len))
		{
			free(var);
			return (ft_strdup(&program->data->envp[i][len + 1]));
		}
		i++;
	}
	free(var); 
	return (ft_strdup(""));
}
