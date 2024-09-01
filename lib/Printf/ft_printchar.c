/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:37:03 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:37:03 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, t_mods *mods)
{
	int		u;
	char	z;
	int		n;

	u = 1;
	if (mods)
		u = max(u, mods->field_width);
	if (mods && mods->zeroed)
		z = '0';
	else
		z = ' ';
	n = 0;
	if (mods)
		n += loop_print(mods && !mods->righted, mods->field_width, 1, z);
	n += write(1, &c, 1);
	if (mods)
		n += loop_print(mods && mods->righted, mods->field_width, 1, z);
	if (n < 1 || (mods && n != u))
		return (-1);
	return (n);
}
