/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmaket_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/19 13:42:42 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_count(t_printf *list, long int n, int fd)
{
	long int	nbr;

	if (n < 0)
	{
		ft_putchar_fd_count(list, '-', fd);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd_count(list, nbr / 10, fd);
	ft_putchar_fd_count(list, (char)(nbr % 10 + '0'), fd);
}

void	ft_putnbr_u_fd_count(t_printf *list, unsigned int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd_count(list, '-', fd);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_u_fd_count(list, nbr / 10, fd);
	ft_putchar_fd_count(list, (char)(nbr % 10 + '0'), fd);
}
