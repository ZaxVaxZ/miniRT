/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:37:29 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:37:29 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	call_prints(char **c, va_list args, t_mods *mods)
{
	if (**c == 'd' || **c == 'i')
		return (ft_printint(va_arg(args, int), mods));
	else if (**c == 'c')
		return (ft_printchar(va_arg(args, int), mods));
	else if (**c == 's')
		return (ft_printstr(va_arg(args, char *), mods));
	else if (**c == 'p')
		return (ft_printaddr(va_arg(args, void *), mods));
	else if (**c == 'u')
		return (ft_printuint(va_arg(args, unsigned int), mods));
	else if (**c == 'x')
		return (ft_printhex(va_arg(args, unsigned int), 0, mods));
	else if (**c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), 1, mods));
	else if (**c == '%')
		return (ft_printchar('%', mods));
	else
		return (-1);
}

int	ft_handlestr(char **c, va_list args)
{
	t_mods	*mods;
	int		ret;

	ret = -1;
	mods = get_mods(c);
	if (!mods)
		return (-1);
	if (mods->prec_width == -5)
	{
		free(mods);
		mods = NULL;
	}
	ret = call_prints(c, args, mods);
	if (mods)
		free(mods);
	(*c)++;
	return (ret);
}
