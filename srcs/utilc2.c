/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:15 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:22:16 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		checkwithstncmp(char *str, char *key)
{
	int i;
	char *tmp;
	int len;

	len = 0;
	i = 0;
	tmp = get_key_from_str(key);
	if (tmp)
	{
		len = ft_strlen(tmp);
		i = ft_strncmp(str, tmp, len);
		if (i < 0)
		{
			free(tmp);
			return(0);
		}
		else if (i == 0)
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

int		boolarrvalue(char **array, char *key)
{
	int i;
	int len;
	int find;
	char *tmp;

	i = 0;
	len =  pp_count_array(array);
	find = 0;
	int lenkey = ft_strlen(key);
	tmp = NULL;
	while(i < len)
	{
		if (!ft_strncmp(array[i], key, lenkey) || checkwithstncmp(array[i], key))
		{
			find = 1;
			tmp = get_value_from_str(array[i]);
			if (tmp)
				find = 2;
			free(tmp);
		}
		i++;
	}
	return(find);
}

char	*get_key(char **array, char *str)
{
	int i;
	int len;
	char *find;

	i = 0;
	len =  pp_count_array(array);
	find = NULL;
	int lenkey = ft_strlen(str);
	while(i < len)
	{
		if (ft_strncmp(array[i], str, lenkey) == 0)
		{
			return (ft_strdup(str)); // для чего то делал
		}
		if (checkwithstncmp(array[i], str))
		{
			return(get_key_from_str(str));
		}
		i++;
	}
	return(find);
}

char	*get_value_by_key(char **array, char *key)
{
	int i;
	int len;
	char *find;

	find = NULL;
	i = 0;
	len =  pp_count_array(array);
	while(i < len)
	{
		if (ft_strncmp(array[i], key, findchar(key, '=')) == 0)
		{
			find = get_value_from_str(array[i]);
		}
		i++;
	}
	return(find);
}

int  find_order_by_key(char **array, char *value)
{
	int i;
	int len;

	i = 0;
	len =  pp_count_array(array);
	while(i < len)
	{
		if (ft_strncmp(array[i], value, ft_strlen(value)) == 0)
			return (i);
		i++;
	}
	return(0);
}
