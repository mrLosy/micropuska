/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:14:36 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	unsigned char	*d;
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen((char *)str);
	i = 0;
	d = (unsigned char *)str;
	if (str)
	{
		while (d[len] != (unsigned char)ch && 0 < len)
		{
			--len;
		}
		if (d[len] == (unsigned char)ch)
		{
			return (void *)(d + len);
		}
	}
	return (0);
}
