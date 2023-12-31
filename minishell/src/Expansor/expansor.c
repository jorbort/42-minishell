/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:45 by juanantonio       #+#    #+#             */
/*   Updated: 2023/12/21 10:46:45 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

char	*(*sj)(char *s1, char *s2);

void	ft_expand(t_program *program)
{
	int		i;
	int		c;
	char	*str;

	c = -1;
	i = -1;
	if (!program->cmd_list)
		return ;
	while (program->cmd_list->cmd[++i] != NULL)
	{
		if (ft_strchr(program->cmd_list->cmd[i], '$') != NULL
			|| ft_strchr(program->cmd_list->cmd[i], '~') != NULL)
		{
			str = ft_strdup(program->cmd_list->cmd[i]);
			ft_expand_var(program, i, c, str);
		}
	}
}

void	ft_expand_var(t_program *program, int i, int c, char *str)
{
	char	*cmd;

	sj = &ft_strjoin_doublefree;
	ft_freegnl(&program->cmd_list->cmd[i]);
	cmd = program->cmd_list->cmd[i];
	cmd = ft_return_var(program, cmd, str, c);
	program->cmd_list->cmd[i] = cmd;
}

char	*ft_return_var(t_program *program, char *cmd, char *str, int c)
{
	int		var_len;
	char	*var_name;

	while (str[++c])
	{
		if (str[c] == '$' || (str[0] == '~' && !str[1]))
		{
			if (str[c] == '$')
				var_name = ft_get_varname(str, c + 1);
			else if (str[0] == '~' && (str[1] == '/' || str[1] == 0))
				var_name = ft_strdup("~");
			var_len = ft_strlen(var_name);
			if (ft_search_quote(str) && var_len != 0)
				cmd = ft_strjoin_free(cmd, get_myenv(program, var_name));
			else if (!ft_search_quote(str) && var_len != 0)
				cmd = sj(cmd, ft_substr(str, c, var_len + 1));
			if (var_len != 0 && str[0] != '~')
				c += var_len;
			else if (str[0] != '~')
				cmd = sj(cmd, ft_substr(str, c, 1));
		}
		else
			cmd = sj(cmd, ft_substr(str, c, 1));
	}
	return (cmd);
}

///implementacion funcion getenv en programa con la copia de env** 
char	*get_myenv(t_program *program, char *var)
{
	int	i;
	int	len;

	i = 0;
	var = ft_strjoin_free(var, "=");
	len = ft_strlen(var);
	while (program->data->envp[i])
	{
		if (!ft_strncmp(var, "~", 1))
		{
			free(var);
			var = ft_strdup("HOME=");
			len = ft_strlen(var);
		}
		if (!ft_strncmp(var, "?", 1))
			return (ft_itoa((*program->exit_code)));
		else if (!ft_strncmp(program->data->envp[i], var, len))
		{
			free(var);
			return (ft_strdup(&program->data->envp[i][len]));
		}
		i++;
	}
	free(var);
	return ("");
}
