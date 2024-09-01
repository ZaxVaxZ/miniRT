/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:56:14 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 16:13:50 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *str)
{
	size_t	i;
	size_t	n;
	char	t;

	i = 0;
	n = ft_strlen(str);
	while (i < n / 2)
	{
		t = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = t;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	ret[20];
	int		i;
	int		neg;
	long	x;

	neg = 1 - 2 * (n < 0);
	x = (long) n * neg;
	i = 0;
	while (x / 10 != 0)
	{
		ret[i++] = x % 10 + 48;
		x /= 10;
	}
	ret[i++] = x % 10 + 48;
	if (neg == -1)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_strrev(ret);
	return (ft_strdup(ret));
}
