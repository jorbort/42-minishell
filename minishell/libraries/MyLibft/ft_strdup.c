/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:31:09 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/21 11:22:18 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			i;
	const char	*str;
	char		*dupstr;

	str = s1;
	i = 0;
	if (!s1 || !*s1)
		return (NULL);
	dupstr = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dupstr)
		return (NULL);
	while (str[i] != 0)
	{
		dupstr[i] = str[i];
		i++;
	}
	dupstr[i] = 0;
	return (dupstr);
}

char	*ft_strdup_clean(const char *s1)
{
	int			i;
	int			j;
	const char	*str;
	char		*dupstr;

	str = s1;
	i = 0;
	j = 1;
	if (!s1 || !*s1)
		return (NULL);
	if (ft_isaquote(s1[0]) && ft_isaquote(s1[ft_strlen(s1) - 1]))
		i = 2;
	else
		j = 0;
	dupstr = malloc((ft_strlen(s1) - i) * sizeof(char) + 1);
	if (!dupstr)
		return (NULL);
	i = 0;
	while (str[j + i] != 0 && !ft_isaquote(s1[j + i]))
	{
		dupstr[i] = str[j + i];
		i++;
	}
	dupstr[i] = 0;
	return (dupstr);
}
