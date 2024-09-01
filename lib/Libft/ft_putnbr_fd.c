/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:36:44 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/11 15:46:52 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenum_fd(long x, int fd)
{
	char	c;

	if (x < 0)
	{
		write(fd, "-", 1);
		ft_writenum_fd(x * -1, fd);
		return ;
	}
	if (x >= 10)
	{
		ft_writenum_fd(x / 10, fd);
	}
	c = (x % 10) + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_writenum_fd((long)n, fd);
}
