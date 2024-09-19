/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:42:34 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/18 04:29:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

void	assign(t_vector *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	cross_vector(t_vector *result, t_vector v1, t_vector v2)
{
	result->x = v1.y * v2.z - v1.z * v2.y;
	result->y = v1.z * v2.x - v1.x * v2.z;
	result->z = v1.x * v2.y - v1.y * v2.x;
}

void	scalar_op(t_vector *res, t_vector *v, char op, double value)
{
	if (v && res && op == '+')
	{
		res->x = v->x + value;
		res->y = v->y + value;
		res->z = v->z + value;
	}
	if (v && res && op == '-')
	{
		res->x = v->x - value;
		res->y = v->y - value;
		res->z = v->z - value;
	}
	if (v && res && op == '*')
	{
		res->x = v->x * value;
		res->y = v->y * value;
		res->z = v->z * value;
	}
	if (v && res && op == '/')
	{
		res->x = v->x / value;
		res->y = v->y / value;
		res->z = v->z / value;
	}
}

void	vector_op(t_vector *res, t_vector *v1, char op, t_vector *v2)
{
	if (v1 && v2 && res && op == '+')
	{
		res->x = v1->x + v2->x;
		res->y = v1->y + v2->y;
		res->z = v1->z + v2->z;
	}
	if (v1 && v2 && res && op == '-')
	{
		res->x = v1->x - v2->x;
		res->y = v1->y - v2->y;
		res->z = v1->z - v2->z;
	}
	if (v1 && v2 && res && op == '*')
	{
		res->x = v1->x * v2->x;
		res->y = v1->y * v2->y;
		res->z = v1->z * v2->z;
	}
	if (v1 && v2 && res && op == '/')
	{
		res->x = v1->x / v2->x;
		res->y = v1->y / v2->y;
		res->z = v1->z / v2->z;
	}
}
