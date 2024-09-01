/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:41:18 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/14 16:41:18 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*da;
	unsigned char	*sa;

	da = (unsigned char *)dst;
	sa = (unsigned char *)src;
	if (n == 0 || da == sa)
		return (da);
	i = 0;
	while (i < n)
	{
		da[i] = sa[i];
		i++;
	}
	return (da);
}
