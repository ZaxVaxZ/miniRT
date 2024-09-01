/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:10:37 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/02 16:10:37 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	if (n[0] == '\0')
		return (h);
	if (len == 0)
		return (NULL);
	i = 0;
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j <= len && (n[j] == h[i + j] || n[j] == '\0'))
		{
			if (n[j] == '\0')
				return (h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
