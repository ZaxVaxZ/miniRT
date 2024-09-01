/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:33:52 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:33:52 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, t_mods *mods)
{
	int	l;
	int	x;
	int	n;

	if (!str)
		str = "(null)";
	l = ft_strlen(str);
	if (mods && mods->prec_width >= 0)
		l = min(l, mods->prec_width);
	if (mods)
		x = max(l, mods->field_width);
	else
		x = l;
	n = 0;
	while (mods && !mods->righted && (mods->field_width)-- > l)
		n += write(1, " ", 1);
	if (mods)
		n += write(1, str, l);
	else
		n += write(1, str, ft_strlen(str));
	while (mods && mods->righted && (mods->field_width)-- > l)
		n += write(1, " ", 1);
	if (n != x)
		return (-1);
	return (n);
}
