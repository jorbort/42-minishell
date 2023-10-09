/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/09 15:49:09 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <includes/minishell.h>

int main(void)
{
	
	char *str;
	int i = 0;
	int f = 0;
	while(42)
	{
		str = readline("	MiniShell: $>");
		while (str[i])
		{
			if (str[i] == '"');
					f++;
		i++;
		}
		if (f != 2)
			str = readline("	$>");

	}
}
