/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:40:26 by ehammoud          #+#    #+#             */
/*   Updated: 2023/12/08 20:40:26 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct modifications
{
	int	sign;
	int	space;
	int	zeroed;
	int	righted;
	int	modified;
	int	prec_width;
	int	field_width;
}	t_mods;

int		ft_handlestr(char **c, va_list args);
int		ft_printaddr(void *address, t_mods *mods);
int		ft_printchar(char c, t_mods *mods);
int		ft_printf(const char *str, ...);
int		ft_printhex(unsigned long x, int cap, t_mods *mods);
int		ft_printint(int x, t_mods *mods);
int		ft_printstr(char *str, t_mods *mods);
int		ft_printuint(unsigned int x, t_mods *mods);
t_mods	*get_mods(char **s);
int		min(int x, int y);
int		max(int x, int y);
int		loop_print(int condition, int num, int end, char c);

#endif