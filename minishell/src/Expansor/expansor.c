/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:45 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/16 13:31:53 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void ft_expand(t_program *program)
{
	int i;

	i = -1;
	while (program->cmd_list->cmd[++i] != NULL)
	{
		printf("%s\n", program->cmd_list->cmd[i]);
		if (ft_strchr(program->cmd_list->cmd[i], '$') != NULL)
			ft_expand_var(program, i);
		printf("%s\n", program->cmd_list->cmd[i]);

	}
}

void ft_expand_var(t_program *program, int i)
{
	char	*str;
	char	*cmd;
	char	*var_name;
	int		c;
	int		exp_flag;

	str = ft_strdup(program->cmd_list->cmd[i]);
	free(program->cmd_list->cmd[i]);
	program->cmd_list->cmd[i] = NULL;
	cmd = program->cmd_list->cmd[i];
	exp_flag = ft_search_quote(str);
	c = -1;
	while (str[++c])
	{
		if (str[c] == '$')
		{
			var_name = ft_get_varname(str, c + 1);
			if (var_name != NULL && exp_flag)
				cmd = ft_strjoin_free(cmd, getenv(var_name));
			else if (var_name != NULL && !exp_flag)
				cmd = ft_strjoin_doublefree(cmd, ft_substr(str, c, ft_strlen(var_name) + 1));
			c += ft_strlen(var_name);
		}
		else
			cmd = ft_strjoin_doublefree(cmd, ft_substr(str, c, 1));
	}
	program->cmd_list->cmd[i] = cmd;
}

int ft_search_quote(char *str)
{
	int i;

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
	while (str[i + j] && ft_isalnum(str[i + j]) && !ft_isspace(str[i + j]))
		j++;
	return (ft_substr(str, i, j));
}

/*
void ft_expand_var(t_program *program, int i)
{
	char	*var;
	char	*expvar;
	char 	*expanstr;
	int		cmdlen;
	int		expvarlen;

	var = get_varname(program, i);
	cmdlen = ft_strlen(program->cmd_list->cmd[i]) - (ft_strlen(var) + 1);
	//printf("%s\n", var);
	expvar = getenv(var);
	if (expvar == NULL)
		expvarlen = 0;
	else
		expvarlen = ft_strlen(expvar);
	//printf("expvar %s leng is %i\n", expvar, expvarlen);
	expanstr = malloc(sizeof(char) * (cmdlen + expvarlen + 1));

	int j = 0;

	char *nstr = program->cmd_list->cmd[i];
	i = 0;
	int a = 0;
	while (nstr[a] != '$')
	{
		expanstr[i] = nstr[a];
		i++;
		a++;
	}
	a++;
	while (ft_isalnum(nstr[a]) && nstr[a])
		a++;
	while(expvar[j])
	{
		expanstr[i] = expvar[j];
		j++;
		i++;
	}
	while(nstr[a])
	{
		expanstr[i] = nstr[a];
		i++;
		a++;
	}
	expanstr[i] = 0;
	program->cmd_list->cmd[i] = expanstr;
	printf("%s\n", program->cmd_list->cmd[i]);
}
*/
