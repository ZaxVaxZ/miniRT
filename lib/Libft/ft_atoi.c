/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:34:55 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/02 13:34:55 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	n;
	int				sign;
	unsigned long	lm;

	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1 - 2 * (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	lm = LONG_MAX;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((str[i] - 48ul > lm % 10 && n == lm / 10) || n > lm / 10)
			return (-1 * (sign == 1));
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}
