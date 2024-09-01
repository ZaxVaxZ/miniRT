/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:37:14 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:37:14 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(long x, int noprint)
{
	int	c;

	if (noprint)
		return (0);
	c = 1;
	if (x < 0)
	{
		x *= -1;
		c++;
	}
	while (x / 10)
	{
		x /= 10;
		c++;
	}
	return (c);
}

static int	print_int(long x, int u, t_mods *mods)
{
	int	n;

	n = 0;
	if (x >= 0 && mods && mods->sign)
		n += write(1, "+", 1);
	if (x >= 0 && mods && mods->space)
		n += write(1, " ", 1);
	if (x < 0)
	{
		n += write(1, "-", 1);
		x *= -1;
	}
	if (mods)
		n += loop_print(mods && mods->zeroed, mods->field_width, u, '0');
	if (mods)
		n += loop_print(mods && !mods->zeroed, mods->prec_width,
				digit_count(x, (!x && mods && mods->prec_width == 0)), '0');
	if (x >= 10)
		n += print_int(x / 10, u, NULL);
	if (x || !mods || (mods && mods->prec_width != 0))
		n += ft_printchar((x % 10) + '0', NULL);
	return (n);
}

int	ft_printint(int x, t_mods *mods)
{
	int	u;
	int	n;

	n = 0;
	u = digit_count(x, (!x && mods && mods->prec_width == 0));
	if (mods)
		u = max(u, mods->prec_width + (x < 0));
	if (x >= 0 && mods)
		u += (mods->sign || mods->space);
	if (mods)
		n += loop_print(mods && !mods->righted && !mods->zeroed,
				mods->field_width, u, ' ');
	n += print_int(x, u, mods);
	if (mods)
		n += loop_print(mods && mods->righted && !mods->zeroed,
				mods->field_width, u, ' ');
	if ((!mods && n != u) || (mods && n != max(mods->field_width, u)))
		return (-1);
	return (n);
}
