/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:42:17 by jbortolo          #+#    #+#             */
/*   Updated: 2023/07/17 13:42:05 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;
	t_list	*temp;

	copy = *lst;
	while (copy)
	{
		temp = copy->next;
		(*del)(copy->content);
		free(copy);
		copy = temp;
	}
	*lst = NULL;
}
