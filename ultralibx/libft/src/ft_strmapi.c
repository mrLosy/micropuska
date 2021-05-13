/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:41:12 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = NULL;
	if (s)
	{
		len = ft_strlen((char*)s);
		str = (char*)malloc(sizeof(char) * len + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				++i;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (0);
}
