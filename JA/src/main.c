/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:39:17 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/11 14:08:44 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main(int ac, char **av)
{
	
	char *str;
	(void) av;
	t_lexer **lexe;

	lexer = NULL;
	if (ac != 1)
		return (1);
	while(42)
	{
		str = readline(BLUE_T"\nMiniShell:" YELLOW_T" $>"RESET_COLOR);
	
		lexe = tokenizer(lexe, str);	
		while (lexe->next != NULL)
		{
			printf("%s\n", lexe->str);
			lexe = lexe->next;
		}
	}
	return (0);
}

