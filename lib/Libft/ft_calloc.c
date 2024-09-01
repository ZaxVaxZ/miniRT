/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:34:48 by ehammoud          #+#    #+#             */
/*   Updated: 2023/11/02 13:34:48 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	if (size == 0 || count == 0)
		return (ft_calloc(1, 1));
	if (count > SIZE_MAX / size)
		return (NULL);
	ret = malloc(count * size);
	if (ret)
	{
		i = 0;
		while (i < count * size)
			((unsigned char *)ret)[i++] = 0;
	}
	return (ret);
}
