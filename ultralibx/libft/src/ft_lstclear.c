/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:53:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/03/21 21:25:57 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	if (*lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			new = *lst;
			*lst = new->next;
			if (new)
				free(new);
		}
	}
	*lst = NULL;
}
