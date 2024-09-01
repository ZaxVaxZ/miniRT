/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:17:19 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/01 16:34:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

int	max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	loop_print(int condition, int num, int end, char c)
{
	int	n;

	n = 0;
	while (condition && (num)-- > end)
		n += write(1, &c, 1);
	return (n);
}
