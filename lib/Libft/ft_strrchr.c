/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:10:46 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/02 16:10:46 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(s);
	i = n + 1;
	while (i-- > 0)
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}
