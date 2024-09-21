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

double	hit_sphere(t_ray *ray, t_object *sp, double *ret)
{
	t_vector	C_Q;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	a = dot(ray->orient, ray->orient);
	vector_op(&C_Q, &sp->origin, '-', &ray->origin);
	b = 2 * dot(ray->orient, C_Q);
	c = dot(C_Q, C_Q) - sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	*ret = -1;
	if (discriminant < 0 || !a)
		return (1);
	if ((-b - sqrt(discriminant)) / (2 * a) > 0)
		*ret = (-b - sqrt(discriminant)) / (2 * a);
	else
		*ret = (-b + sqrt(discriminant)) / (2 * a);
	// 	if (!hit_sphere(&ray, &m->scene.spheres[0], &ret) && ret >= 0)
	// 	{
	// 		scalar_op(&ray.orient, &ray.orient, '*', ret);
	// 		vector_op(&ray.orient, &ray.orient, '+', &ray.origin);
	// 		vector_op(&ray.orient, &ray.orient, '-', &m->scene.spheres[0].origin);
	// 		scalar_op(&ray.orient, &ray.orient, '+', 1);
	// 		scalar_op(&ray.orient, &ray.orient, '*', 0.5);
	// 		color_pixel(m, j, i, color_to_hex(ray.orient));
	// 	}
	return (0);
}

void	normal_at(t_vector *ret, t_ray *ray, t_object *o, double t)
{
	ret->x = ray->origin.x + t * ray->orient.x - o->origin.x;
	ret->y = ray->origin.y + t * ray->orient.y - o->origin.y;
	ret->z = ray->origin.z + t * ray->orient.z - o->origin.z;
	scalar_op(ret, ret, '/', sqrt(dot(*ret, *ret)));
	scalar_op(ret, ret, '+', 1);
	scalar_op(ret, ret, '*', 0.5);
}
