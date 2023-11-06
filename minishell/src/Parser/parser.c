/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/10/10 09:13:25 by jorge             #+#    #+#             */
/*   Updated: 2023/10/30 17:59:56 by jbortolo         ###   ########.fr       */
=======
/*   Created: 2023/10/31 17:44:14 by jorge             #+#    #+#             */
/*   Updated: 2023/11/01 19:09:37 by jorge            ###   ########.fr       */
>>>>>>> a3eb437b70dff184f167dbb14770df546915ed2c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*init_cmd(t_parser *pars)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	del_redirs(pars);
	arg_size = count_args(pars->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		ft_error(pars->program, 3);
	tmp = pars->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&pars->lexer_list, tmp->i);
			tmp = pars->lexer_list;
		}
		arg_size--;
	}
	return (t_cmd_new(str,pars->num_redirections,pars->redirections));
}

static bool	pipe_error(t_program *program, t_token token)
{
	if (token == PIPE)
	{
		ft_error(program,1);
		return (false);
	}
	if (!program->lex_list)
	{
		ft_error(program,3);
		return (false);
	}
	return (true);
}


bool	ft_parser(t_program *program)
{
<<<<<<< HEAD
	t_cmd			*node;
	//t_lexer			*tmp;
=======
	t_cmd		*node;
	t_parser	aux;
>>>>>>> a3eb437b70dff184f167dbb14770df546915ed2c

	program->cmd_list = NULL;
	ft_count_pipes(program->lex_list, program);
	if (program->lex_list->token == PIPE)
		return(ft_error(program,1));
	while (program->lex_list)
	{
		if (program->lex_list && program->lex_list->token == PIPE)
			ft_lexerdelone(&program->lex_list, program->lex_list->i);
<<<<<<< HEAD
		if (program->lex_list->token == PIPE)
			ft_error(program, 2);
		//tmp = program->lex_list;
		node = get_cmd(program);
=======
		if (!pipe_error(program, program->lex_list->token))
			return (false);
		aux = init_parser(program->lex_list, program);
		node = init_cmd(&aux);
>>>>>>> a3eb437b70dff184f167dbb14770df546915ed2c
		if (!node)
			ft_error(program,3);
		if (!program->cmd_list)
			program->cmd_list = node;
		else
			ft_cmd_addback(&program->cmd_list, node);
<<<<<<< HEAD
		if (node)
			free(node);
		//program->lex_list = tmp;
=======
		program->lex_list = aux.lexer_list;
>>>>>>> a3eb437b70dff184f167dbb14770df546915ed2c
	}
	return (true);
}