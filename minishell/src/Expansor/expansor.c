/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:45 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/15 13:10:11 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

void expand(t_program *program)
{
	int i;

	i = -1;
	while (program->cmd_list->cmd[++i] != NULL)
	{
		printf("%s\n", program->cmd_list->cmd[i]);
		if (ft_strchr(program->cmd_list->cmd[i], '$') != NULL)
			expand_var(program, i);
	}
}

void expand_var(t_program *program, int i)
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

char *get_varname(t_program *program, int i)
{
	int		j;
	int		y;
	char	*str;

	j = 0;
	str = program->cmd_list->cmd[i];
	while (str[j] != '$')
		j++;
	y = ++j;
	while (str[j] && ft_isalnum(str[j]) && !ft_isspace(str[j]))
		j++;
	return (ft_substr(str, y, (j - y)));
}
