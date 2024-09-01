/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:32:48 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:32:48 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(unsigned int x, int noprint)
{
	int	c;

	if (noprint)
		return (0);
	c = 1;
	while (x / 10)
	{
		x /= 10;
		c++;
	}
	return (c);
}

int	ft_printuint(unsigned int x, t_mods *mods)
{
	int	n;
	int	u;

	u = digit_count(x, (!x && mods && mods->prec_width == 0));
	n = 0;
	if (mods)
		u = max(u, mods->prec_width);
	if (mods)
		n += loop_print(!mods->zeroed && !mods->righted,
				mods->field_width, u, ' ');
	if (mods)
		n += loop_print(mods->zeroed, mods->field_width, u, '0');
	if (mods)
		n += loop_print(!mods->zeroed, mods->prec_width,
				digit_count(x, (!x && mods && mods->prec_width == 0)), '0');
	if (x > 9)
		n += ft_printuint(x / 10, NULL);
	if (x || !mods || (mods && mods->prec_width != 0))
		n += ft_printchar((x % 10) + '0', NULL);
	if (mods)
		n += loop_print(!mods->zeroed && mods->righted,
				mods->field_width, u, ' ');
	if ((!mods && n != u) || (mods && n != max(mods->field_width, u)))
		return (-1);
	return (n);
}
