/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:59:31 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*addr;
	unsigned int	nbytes;

	nbytes = num * size;
	addr = malloc(nbytes);
	if (!size || !num || (size == 0 && num == 0))
		return ((void *)addr);
	if (!addr)
		return (NULL);
	else
	{
		ft_memset(addr, '\0', nbytes);
	}
	return ((void *)addr);
}
