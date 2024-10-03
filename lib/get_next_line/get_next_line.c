/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:16:19 by ehammoud          #+#    #+#             */
/*   Updated: 2023/12/08 17:02:33 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1u];
	char		*ret;
	int			bytes;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	ret = NULL;
	while (!ret || !ft_strchr(ret, '\n'))
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes == 0)
				return (ret);
			if (bytes < 0 && ret)
				free (ret);
			if (bytes < 0)
				return (NULL);
			buffer[bytes] = '\0';
		}
		ret = ft_add_next(ret, buffer);
	}
	return (ret);
}
