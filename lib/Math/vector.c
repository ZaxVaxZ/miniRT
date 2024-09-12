/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:42:34 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/10 16:09:56 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

void	cross_vector(t_vector *result, t_vector v1, t_vector v2)
{
	result->x = v1.y * v2.z - v1.z * v2.y;
	result->y = v1.z * v2.x - v1.x * v2.z;
	result->z = v1.x * v2.y - v1.y * v2.x;
}

float	magnitude(t_vector v)
{
	return (sqrt(dot(v, v)));
}

void	copy_vector(t_vector *dest, const t_vector *src)
{
	if (!dest || !src)
		return ;
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}