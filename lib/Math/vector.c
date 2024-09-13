/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:42:34 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/13 21:15:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

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

void	scalar_op(t_vector *v, char op, float value)
{
	if (v && op == '+')
	{
		v->x += value;
		v->y += value;
		v->z += value;
	}
	if (v && op == '-')
	{
		v->x -= value;
		v->y -= value;
		v->z -= value;
	}
	if (v && op == '*')
	{
		v->x *= value;
		v->y *= value;
		v->z *= value;
	}
	if (v && op == '/')
	{
		v->x /= value;
		v->y /= value;
		v->z /= value;
	}
}

void	normalize(t_vector *v)
{
	if (!v)
		return ;
	scalar_op(v, '/', magnitude(*v));
}
