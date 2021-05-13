/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:48:14 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 11:13:02 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_isspace(char c, char b)
{
	return (c == b);
}

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str, c))
			str++;
		if (*str && !ft_isspace(*str, c))
		{
			count++;
			while (*str && !ft_isspace(*str, c))
				str++;
		}
	}
	return (count);
}

static char	*malloc_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_isspace(str[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(const char *str, char c)
{
	char	**arr;
	int		i;

	i = 0;
	arr = NULL;
	if (str && (arr = malloc(sizeof(char *) * \
		(count_words((char*)str, c) + 1))))
	{
		while (*str)
		{
			while (*str && ft_isspace(*str, c))
				str++;
			if (*str && !ft_isspace(*str, c))
			{
				arr[i] = malloc_word((char*)str, c);
				i++;
				while (*str && !ft_isspace(*str, c))
					str++;
			}
		}
		arr[i] = NULL;
	}
	return (arr);
}
