/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/10/19 16:52:17 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_parser(t_lexer *lex_list)
{
	t_cmd	*cmd_list;

	
	get_cmd(lex_list, cmd_list);
}

void	get_cmd(t_lexer *lex_list, t_cmd *cmd_list)
{
	char	**str;
	int		i;
	t_lexer	*temp;
	int		pipes_num;

	i = 0;
	pipes_num = count_pipes();//to-do funcion que cuente los pipes para saber el numero de comandos 
	str = ft_calloc((pipes_num + 1),sizeof(char *));
	if (!str)
		ft_error();//to-do
	temp = lex_list;
	while (lex_list)
	{
		
		if (handle_redir(lex_list, cmd_list) == true)
			ft_lexerdelone(lex_list); 
		if (is_pipe(lex_list->str) == true)
			ft_pipe_error(lex_list);
		if (temp->str)
		{
			str[i++] = ft_strdup(temp->str);
			ft_lexer_del(lex_list, i);
			temp = lex_list->str;
		}
		pipes_num--;
	}
	cmd_list->cmd = t_cmd_new(str,);
}
