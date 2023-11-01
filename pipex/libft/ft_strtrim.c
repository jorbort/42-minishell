/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:36:38 by jbortolo          #+#    #+#             */
/*   Updated: 2023/05/09 11:20:15 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_in(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		start;
	int		len;

	i = 0;
	start = 0;
	len = ft_strlen(s1);
	while (s1[i] != '\0' && is_in(s1[i], set) != 0)
	{
		start++;
		i++;
	}
	while (len > start && is_in(s1[len - 1], set))
	{
		len--;
	}
	ptr = malloc((len - start) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < len)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
