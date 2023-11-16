/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:24:28 by jbortolo          #+#    #+#             */
/*   Updated: 2023/06/15 15:26:20 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*empty(char *arr_fd)
{
	char	*new_arr;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(arr_fd, '\n');
	if (!ptr)
	{
		new_arr = NULL;
		return (ft_free_gnl(&arr_fd));
	}
	else
		len = (ptr - arr_fd) + 1;
	if (!arr_fd[len])
		return (ft_free_gnl(&arr_fd));
	new_arr = ft_substr_gnl(arr_fd, len, ft_strlen_gnl(arr_fd) - len);
	ft_free_gnl(&arr_fd);
	if (!new_arr)
		return (NULL);
	return (new_arr);
}

static char	*next_l(char *arr_fd)
{
	char	*ptr;
	int		len;
	char	*line;

	ptr = ft_strchr_gnl(arr_fd, '\n');
	len = (ptr - arr_fd) + 1;
	line = ft_substr_gnl(arr_fd, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*parse_buff(int fd, char *arr_fd)
{
	int		i;
	char	*tmp_buff;

	i = 1;
	tmp_buff = malloc(sizeof(char) * (30 + 1));
	if (!tmp_buff)
		return (ft_free_gnl(&arr_fd));
	tmp_buff[0] = '\0';
	while (i > 0 && !ft_strchr_gnl(tmp_buff, '\n'))
	{
		i = read(fd, tmp_buff, 30);
		if (i > 0)
		{
			tmp_buff[i] = '\0';
			arr_fd = ft_strjoin_gnl(arr_fd, tmp_buff);
		}
	}
	free(tmp_buff);
	if (i == -1)
		return (ft_free_gnl(&arr_fd));
	return (arr_fd);
}

char	*get_next_line_gnl(int fd)
{
	static char	*arr_fd[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((arr_fd[fd] && !ft_strchr_gnl(arr_fd[fd], '\n')) || !arr_fd[fd])
		arr_fd[fd] = parse_buff(fd, arr_fd[fd]);
	if (!arr_fd[fd])
		return (NULL);
	line = next_l(arr_fd[fd]);
	if (!line)
		return (ft_free_gnl(&arr_fd[fd]));
	arr_fd[fd] = empty(arr_fd[fd]);
	return (line);
}
