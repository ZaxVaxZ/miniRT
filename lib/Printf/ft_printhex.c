/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:37:10 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:37:10 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(unsigned long n, int noprint)
{
	int	x;

	if (noprint)
		return (0);
	x = 1;
	while (n / 16)
	{
		x++;
		n /= 16;
	}
	return (x);
}

static int	print_hex(unsigned long x, char *h, int noprint)
{
	int	n;

	if (noprint)
		return (0);
	n = 0;
	if (x > 15)
		n = print_hex(x / 16, h, 0);
	if (n == -1)
		return (-1);
	if (ft_printchar(h[x % 16], NULL) == -1)
		return (-1);
	return (n + 1);
}

static int	calc_total(t_mods *mods, unsigned long x)
{
	int	u;

	u = hexlen(x, (!x && mods && mods->prec_width == 0));
	if (x && mods && mods->modified)
		u += 2;
	if (mods && mods->prec_width
		> hexlen(x, (!x && mods && mods->prec_width == 0)))
		u += mods->prec_width - hexlen(x,
				(!x && mods && mods->prec_width == 0));
	return (u);
}

static int	pre_printhex(t_mods *mods, int u, unsigned long x)
{
	int	n;

	n = 0;
	if (mods)
		n += loop_print(mods && mods->zeroed,
				mods->field_width, u, '0');
	if (mods)
		n += loop_print(mods && !mods->zeroed, mods->prec_width,
				hexlen(x, (!x && mods && mods->prec_width == 0)), '0');
	return (n);
}

int	ft_printhex(unsigned long x, int cap, t_mods *mods)
{
	int		u;
	int		n;
	char	*h;

	h = "0123456789abcdef";
	if (cap)
		h = "0123456789ABCDEF";
	u = calc_total(mods, x);
	n = 0;
	if (mods)
		n += loop_print(mods && !mods->zeroed
				&& !mods->righted, mods->field_width, u, ' ');
	if (cap && mods && mods->modified && x)
		n += write(1, "0X", 2);
	else if (mods && mods->modified && x)
		n += write(1, "0x", 2);
	n += pre_printhex(mods, u, x);
	n += print_hex(x, h, (!x && mods && mods->prec_width == 0));
	if (mods)
		n += loop_print(mods && mods->righted, mods->field_width, u, ' ');
	if ((!mods && n != u) || (mods && mods->field_width > 1
			&& n != max(u, mods->field_width)))
		return (-1);
	return (n);
}
