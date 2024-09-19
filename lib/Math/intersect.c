/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:01:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/17 17:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	intersect_sphere(t_ray *ray, t_object *sp, double *ret)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot(ray->orient, ray->orient);
	b = 2 * dot(ray->origin, ray->orient);
	c = dot(ray->origin, ray->origin) * sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (1);
	*ret = (-b + sqrt(discriminant)) / (2 * a);
	return (0);
}
