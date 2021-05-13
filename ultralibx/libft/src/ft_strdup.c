/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:43:44 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/20 13:23:22 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*test;
	int		len;

	len = ft_strlen((char *)str) + 1;
	if (!(test = malloc(len * sizeof(char))))
		return (NULL);
	if (test == NULL)
		return (NULL);
	ft_strlcpy(test, str, (unsigned int)len);
	return (test);
}
