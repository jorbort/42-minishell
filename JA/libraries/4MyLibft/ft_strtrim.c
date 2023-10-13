/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:23:43 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 14:23:10 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		b;
	int		start;
	char	*trim;

	b = 2;
	i = 0;
	if (!s1)
		return (NULL);
	if ((int)s1[i] == 0)
		b = 1;
	while (ft_strchr(set, (int)s1[i]) != 0 && s1[i] != 0)
		i++;
	start = i;
	i = ft_strlen(s1);
	while (ft_strchr(set, (int)s1[i]) != 0 && i > 0)
		i--;
	if (start > i)
		return (ft_strdup("\0"));
	trim = malloc((i - start) * sizeof(char) + b);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], (i - start) + b);
	return (trim);
}

/*int main(void)
{
	char *str = "11   Hello World!!!!11   ";
	char *set = "   1 ";

	printf("%s", ft_strtrim(str,set));
}*/
