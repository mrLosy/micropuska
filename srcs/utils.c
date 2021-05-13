/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:35 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:08:08 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_isprint_s(int c)
{
	return (c >= 33 && c <= 126);
}

void	close_fds(int i, int **fd, int last)
{
	int j;

	j = -1;
	while (++j < i)
	{
		if (j < (i - 1))
			close(fd[j][0]);
		close(fd[j][1]);
	}
	while (++j <= last)
	{
		if (j == last)
			close(fd[j - 1][0]);
		else
		{
			close(fd[j - 1][0]);
			close(fd[j][1]);
		}
	}
}

char **add_arrayelem(char **array, char *str)
{
	int len;
	char **tmp;
	int i;

	len = pp_count_array(array);
	tmp = (char **)ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i <= len)
	{
		if (i == len + 1 && len)
			tmp[i] = ft_strdup(str);
		else if (len && len != i)
			tmp[i] = ft_strdup(array[i]);
		else if((!len && !i) || (i == len))
			tmp[i] = ft_strdup(str);
		i++;
	}
	tmp[i] = NULL;
	free_array(array);
	return(tmp);
}


char **delete_arrayelem(char **array, int order)
{
	int len;
	char **tmp;
	int i;
	int j;

	len = pp_count_array(array);

	tmp = (char **)ft_calloc(sizeof(char *), len);
	i = 0;
	j = 0;
	while (array[i])
	{
		if(i == order)
		{
			i++;
		}
		if (i == len)
		{
			tmp[len] = NULL;
			free_array(array);
			return(tmp);
		}
		if (i != order)
		{
			tmp[j] = ft_strdup(array[i]);
		}
		i++;
		j++;
	}
	tmp[len] = NULL;
	free_array(array);
	return(tmp);
}

