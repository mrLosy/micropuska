/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:46:41 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	if (!n)
		return (0);
	i = 0;
	d = (unsigned char*)buf1;
	s = (unsigned char*)buf2;
	while (d[i] == s[i] && n - 1 > i)
		i++;
	if (d[i] != s[i])
		return (d[i] - s[i]);
	else
		return (0);
}
