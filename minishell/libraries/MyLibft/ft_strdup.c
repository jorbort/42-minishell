/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:31:09 by juan-anm          #+#    #+#             */
/*   Updated: 2024/01/02 09:44:40 by jorgebortol      ###   ########.fr       */
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

static char	*allocate_and_copy_string(const char *str, int i, int j)
{
	char	*dupstr;
	int		length;

	length = ft_strlen(str);
	if (ft_isaquote(str[0]) && ft_isaquote(str[length - 1]))
		i = 2;
	else
		j = 0;
	dupstr = malloc((length - i) * sizeof(char) + 1);
	if (!dupstr)
		return (NULL);
	i = 0;
	while (str[j + i] != 0 && !ft_isaquote(str[j + i]))
	{
		dupstr[i] = str[j + i];
		i++;
	}
	dupstr[i] = 0;
	return (dupstr);
}

char	*ft_strdup_clean(char *s1)
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
	dupstr = allocate_and_copy_string(str, i, j);
	free(s1);
	return (dupstr);
}
