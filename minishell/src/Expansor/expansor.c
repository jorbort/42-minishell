/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:45 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/14 13:03:08 by juanantonio      ###   ########.fr       */
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
        if (ft_strchr(program->cmd_list->cmd[++i], '$') != NULL)
            expand_var(program, i);
        
    }
}

void expand_var(t_program *program, int i)
{
    char    *var;
    int     cmdlen;
    int     varlen;

    var = get_var(program->cmd_list->cmd[i]);
    cmdlen = ft_strlen(program->cmd_list->cmd[i]);

}

char *get_varname(t_program *program, int i)
{
    int j;
    int y;
    char *str;
    char *var;

    str = program->cmd_list->cmd[i];
    while (str[j] != '$')
        j++;
    y = j;
    while (str[j] && !ft_isalnum(str[j]) && !ft_isspace(str[j]))
        j++;
    return (ft_substr(str,y,(y - j)));

}