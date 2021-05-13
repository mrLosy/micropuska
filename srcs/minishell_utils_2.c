/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:06 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:07 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ctrl_d()
{
	write(2, "exit\n", 5);
	exit(0);
}

void	canon_term_on(t_all *all)
{
	all->term.c_lflag |= ECHO;
	all->term.c_lflag |= ICANON;
	all->term.c_lflag |= ISIG;
	tcsetattr(0, TCSANOW, &all->term);
}

void	canon_term_off(t_all *all)
{
	all->term.c_lflag &= ~(ECHO);
	all->term.c_lflag &= ~(ICANON);
	all->term.c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, &all->term);
}

void		sort_swap(char **a, char **b)
{
	char *tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void		sort_by_ascii(char **array)
{
	int		complete;
	int		i;
	int		env_len;

	i = 0;
	env_len = pp_count_array(array);
	complete = 0;
	while (array && complete == 0)
	{
		complete = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				sort_swap(&array[i], &array[i + 1]);
				complete = 0;
			}
			i++;
		}
		env_len--;
	}
}
