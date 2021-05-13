/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:43:54 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	int					i;

	i = 0;
	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (!n || destination == source)
		return (destination);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (destination);
}
