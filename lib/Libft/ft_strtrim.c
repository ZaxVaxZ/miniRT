/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:10:52 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/19 16:43:46 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char const *set, char c)
{
	int	i;

	if (!set || set[0] == '\0')
		return (0);
	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	b;
	size_t	e;

	if (!s1 || !set || s1[0] == '\0' || set[0] == '\0')
		return (ft_strdup(s1));
	b = 0;
	while (s1[b] != '\0' && is_in(set, s1[b]))
		b++;
	if (b == ft_strlen(s1))
		return (ft_strdup(""));
	e = ft_strlen(s1) - 1;
	while (e > 0 && is_in(set, s1[e]))
		e--;
	return (ft_substr(s1, b, e - b + 1));
}
