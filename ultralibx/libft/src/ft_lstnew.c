/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:06:10 by mdenys            #+#    #+#             */
/*   Updated: 2021/03/25 20:05:56 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = (t_list*)malloc(sizeof(t_list));
	if (str)
	{
		str->content = content;
		str->next = NULL;
		return (str);
	}
	return (NULL);
}
