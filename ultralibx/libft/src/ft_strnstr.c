/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:43:20 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t size)
{
	unsigned int		i;
	unsigned int		j;

	if (ndl[0] == '\0')
		return ((char *)hst);
	i = 0;
	while (hst[i])
	{
		j = 0;
		if (hst[i] == ndl[j])
		{
			while (hst[i + j] == ndl[j] && i + j < size)
			{
				j++;
				if (!ndl[j])
					return ((void *)(hst + i));
			}
		}
		i++;
	}
	return (0);
}
