/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:10:10 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/02 16:10:10 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_n;
	size_t	dst_n;

	src_n = ft_strlen(src);
	dst_n = ft_strlen(dst);
	if (!dst && dstsize == 0)
		return (src_n);
	if (dstsize == 0 || dst_n >= dstsize)
		return (src_n + dstsize);
	i = 0;
	while (src[i] != '\0' && i + dst_n + 1 < dstsize)
	{
		dst[i + dst_n] = src[i];
		i++;
	}
	dst[i + dst_n] = '\0';
	return (dst_n + src_n);
}
