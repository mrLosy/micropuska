/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldenis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:14 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:15 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		find_equal(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	print_array_export2(char **arr)
{
	int		i;
	char	*tempvalue;
	char	*tempkey;

	tempvalue = NULL;
	tempkey = NULL;
	i = 0;
	while (arr[i])
	{
		tempkey = get_key_from_str(arr[i]);
		tempvalue = get_value_from_str(arr[i]);
		if (find_equal(arr[i], '='))
			if (tempvalue)
				ft_printf("declare -x %s=\"%s\"\n", tempkey, tempvalue);
			else
				ft_printf("declare -x %s=\"\"\n", tempkey);
		else if (tempvalue)
			ft_printf("declare -x %s\n", tempkey);
		else if (ft_strlen(arr[i]))
			ft_printf("declare -x %s\n", tempkey);
		free(tempkey);
		free(tempvalue);
		i++;
	}
}

void	print_env(char **arr)
{
	int		i;
	char	*tempvalue;
	char	*tempkey;

	i = 0;
	tempvalue = NULL;
	tempkey = NULL;
	while (arr[i])
	{
		tempkey = get_key_from_str(arr[i]);
		tempvalue = get_value_from_str(arr[i]);
		if (find_equal(arr[i], '=') && !tempvalue)
			ft_printf("%s=\n", tempkey);
		else if (tempvalue)
			ft_printf("%s=%s\n", tempkey, tempvalue);
		free(tempkey);
		free(tempvalue);
		i++;
	}
}
