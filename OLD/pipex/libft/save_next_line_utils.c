/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:46:27 by jorge             #+#    #+#             */
/*   Updated: 2023/08/26 00:58:05 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_len_until(const char *str, const char to_find)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
	{
		count++;
		if (str[count - 1] == to_find)
			break ;
	}
	return (count);
}

char	*copy_from_src(char *dest, const char *src, unsigned int len)
{
	unsigned int	index;

	if (!src || !dest)
		return (dest);
	index = 0;
	while (index <= len)
	{
		(dest)[index] = (src)[index];
		index++;
	}
	return (dest);
}

char	*null_calloc(char **str, unsigned int count, unsigned int size)
{
	void			*p;
	unsigned int	index;

	index = 0;
	p = malloc(count * size);
	if (p == ((void *)0))
		return (NULL);
	while ((count * size) > index)
		((char *)p)[index++] = 0;
	*str = p;
	if (!*str)
		return (NULL);
	return (*str);
}

void	free_if_not_empty(char	**str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

size_t	scan_for_nl(const char *src)
{
	while (*src)
	{
		if (*src == '\n')
			return (1);
		src++;
	}
	return (0);
}
