/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:36:59 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:36:59 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(unsigned long n)
{
	int	x;

	x = 1;
	while (n / 16)
	{
		x++;
		n /= 16;
	}
	return (x);
}

int	ft_printaddr(void *address, t_mods *mods)
{
	int	n;
	int	x;

	n = 0;
	x = hexlen((unsigned long)address) + 2;
	if (mods && !mods->zeroed)
		x = max(mods->field_width, x);
	if (mods)
		n += loop_print(!mods->righted && !mods->zeroed,
				mods->field_width, (hexlen((unsigned long) address) + 2), ' ');
	n += ft_printstr("0x", NULL);
	n += ft_printhex((unsigned long)address, 0, NULL);
	if (mods)
		n += loop_print(mods->righted, mods->field_width,
				(hexlen((unsigned long) address) + 2), ' ');
	if (n != x)
		return (-1);
	return (n);
}
