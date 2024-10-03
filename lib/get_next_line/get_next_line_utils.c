/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:18:26 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/15 20:40:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memmove(void *dst, const void *src, size_t count)
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

static void	special_join(char *full, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	if (!full)
		return ;
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		full[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		full[i + j] = s2[j];
		j++;
	}
	full[i + j] = s2[j];
	if (s2[j] == '\n')
		full[i + j + 1] = '\0';
}

char	*ft_add_next(char *line, char *buffer)
{
	char	*ret;
	char	*tmp;

	if (!buffer)
		return (line);
	if (!line)
		ret = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	else
		ret = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	special_join(ret, line, buffer);
	if (line)
		free(line);
	tmp = ft_strchr(buffer, '\n');
	if (tmp)
		ft_memmove(buffer, tmp + 1, ft_strlen(tmp + 1) + 1);
	else
		buffer[0] = '\0';
	return (ret);
}
