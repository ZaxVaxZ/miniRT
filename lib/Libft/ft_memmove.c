/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:36:25 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/02 13:36:25 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	i = 0;
	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	if (count == 0 || dst == src)
		return (dst);
	if (ucdst > ucsrc)
		while (count--)
			ucdst[count] = ucsrc[count];
	else
	{
		while (i < count)
		{
			ucdst[i] = ucsrc[i];
			i++;
		}
	}
	return (dst);
}
