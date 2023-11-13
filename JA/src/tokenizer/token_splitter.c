/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:38 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/13 13:28:38 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_pipesplit(char const *s)
{
	char	**split;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_pipecntwrds(s);
	printf("number of w :%i \n", nwords);
	split = ft_calloc((nwords + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (nwords != 0)
	{
		if (ft_pipesplipri(split, (char *)s) == NULL)
			return (NULL);
	}
	else
		split[0] = NULL;
	return (split);
}

int	ft_pipecntwrds(char const *s)
{
	int	contl;
	int	contw;
	int	i;

	i = 0;
	contw = 0;
	contl = 0;
	return (cntallwrds(i, contl, contw, (char *)s));
}

int	cntallwrds(int i, int contl, int contw, char *s)
{
	char	quote;

	while (s[i])
	{
		if (!ft_isspchar(s[i]))
			contl++;
		if (ft_isspchar(s[i]) & !ft_isspchar(s[i + 1]) && contl > 0)
		{
			contw++;
			contl = 0;
		}
		if (ft_isapipe(s[i]) && !ft_isapipe(s[i + 1]))
			contw++;
		if (ft_isaquote(s[i]))
		{
			quote = s[i++];
			while (s[i] != quote && s[i + 1])
				i++;
			contw++;
		}
		i++;
	}
	if (contl > 0)
		contw++;
	return (contw);
}

char	**ft_pipesplipri(char **split, char *s)
{
	int		i;
	char	*reset;

	i = 0;
	while (i < ft_pipecntwrds(s))
	{
		split[i] = ft_pipestrdupli(s, 0);
		if (split[i] == NULL)
			return (ft_freesp(split));
		i++;
	}
	split[i] = NULL;
	reset = ft_pipestrdupli(s, 1);
	free (reset);
	return (split);
}

char	*ft_pipestrdupli(char *s, int reset)
{
	static int	i = 0;
	int			j;
	int			a;
	char		*dupstr;

	if (reset == 1)
		return (i = 0, NULL);
	a = 0;
	while (s[i] == 32)
		i++;
	j = i;
	i = dupstrlen(s, i);
	dupstr = malloc((i - j) * sizeof(char) + 1);
	if (!dupstr)
		return (NULL);
	while (j < i)
	{
		dupstr[a] = s[j];
		j++;
		a++;
	}
	dupstr[j] = 0;
	return (dupstr);
}
