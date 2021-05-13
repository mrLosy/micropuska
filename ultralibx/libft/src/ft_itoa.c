/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:26:38 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			nbleng(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char				*ft_itoa(int n)
{
	char			*dst;
	unsigned int	leng;
	unsigned int	nbr;
	unsigned int	i;

	nbr = (n < 0 ? -n : n);
	leng = nbleng(nbr);
	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * leng + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		dst[i] = '-';
		leng++;
	}
	i = leng - 1;
	while (nbr >= 10)
	{
		dst[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	dst[i] = nbr % 10 + '0';
	dst[leng] = '\0';
	return (dst);
}
