/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:37:06 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 18:37:06 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		n;
	int		ret;
	va_list	args;

	va_start(args, str);
	ret = 0;
	while (*str != '\0')
	{
		n = ret;
		if (*str == '%')
		{
			str++;
			ret += ft_handlestr((char **)&str, args);
		}
		else
			ret += ft_printchar(*(str++), NULL);
		if (ret < n)
			return (-1);
	}
	va_end(args);
	return (ret);
}
