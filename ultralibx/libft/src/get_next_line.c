/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:47:35 by mdenys            #+#    #+#             */
/*   Updated: 2021/03/21 21:25:46 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*check_reminder(char *reminder)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reminder)
		return (0);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		if (reminder)
			free(reminder);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen_custom(reminder) - i) + 1))))
		return (0);
	i++;
	while (reminder[i])
		rtn[j++] = reminder[i++];
	rtn[j] = '\0';
	if (reminder)
		free(reminder);
	return (rtn);
}

char	*gnl(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*reminder;
	int				r_d;

	r_d = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_rn(reminder) && r_d != 0)
	{
		if ((r_d = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			if (buff)
				free(buff);
			return (-1);
		}
		buff[r_d] = '\0';
		reminder = ft_strjoin_custom(reminder, buff);
	}
	if (buff)
		free(buff);
	*line = gnl(reminder);
	reminder = check_reminder(reminder);
	if (r_d == 0)
		return (0);
	return (1);
}
