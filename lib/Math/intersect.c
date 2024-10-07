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

static double	solve_quadratic(double vals[5])
{
	double	tmp;

	vals[DISC] = vals[B] * vals[B] - 4.0 * vals[A] * vals[C];
	if (vals[DISC] < 0 || !vals[A])
		return (-1);
	vals[RES] = (-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]);
	tmp = (-vals[B] + sqrt(vals[DISC])) / (2 * vals[A]);
	if (vals[RES] <= 0 || tmp < vals[RES])
		vals[RES] = tmp;
	return (vals[RES]);
}

int	hit_sphere(t_ray ray, t_object *sp, t_hit *hit)
{
	double		vals[5];
	t_vector	c_q;

	vals[A] = dot(ray.orient, ray.orient);
	vector_op(&c_q, &sp->origin, '-', &ray.origin);
	vals[B] = -2.0 * dot(ray.orient, c_q);
	vals[C] = dot(c_q, c_q) - sp->radius * sp->radius;
	vals[RES] = solve_quadratic(vals);
	if (vals[RES] >= 0 && (hit->closest == -1 || vals[RES] < hit->closest))
	{
		hit->closest = vals[RES];
		scalar_op(&hit->hitp, &ray.orient, '*', vals[RES]);
		vector_op(&hit->hitp, &hit->hitp, '+', &ray.origin);
		copy_vector(&hit->color, &sp->color);
		vector_op(&hit->normal, &hit->hitp, '-', &sp->origin);
		normalize(&hit->normal);
		hit->obj = sp;
		return (1);
	}
	return (0);
}

int	hit_plane(t_ray ray, t_object *pl, t_hit *hit)
{
	t_vector	tmp;
	double		result;
	double		denominator;

	denominator = dot(pl->orient, ray.orient);
	if (denominator >= -1e-6 && denominator <= 1e-6)
		return (0);
	vector_op(&tmp, &pl->origin, '-', &ray.origin);
	result = dot(tmp, pl->orient) / denominator;
	if (result < 1e-6)
		return (0);
	if (result >= 0 && (hit->closest == -1 || result < hit->closest))
	{
		hit->closest = result;
		scalar_op(&hit->hitp, &ray.orient, '*', result);
		vector_op(&hit->hitp, &hit->hitp, '+', &ray.origin);
		copy_vector(&hit->color, &pl->color);
		copy_vector(&hit->normal, &pl->orient);
		if (dot(hit->normal, ray.orient) > 0)
			scalar_op(&hit->normal, &hit->normal, '*', -1);
		normalize(&hit->normal);
		hit->obj = pl;
		return (1);
	}
	return (0);
}

int	hit_cylinder(t_ray ray, t_object *cy, t_hit *hit)
{
	double		vals[5];
	t_vector	cy_right;
	t_vector	c_q;

	cross_vector(&cy_right, ray.orient, cy->orient);
	vector_op(&c_q, &cy->origin, '-', &ray.origin);
	cross_vector(&c_q, c_q, cy->orient);
	vals[A] = dot(cy_right, cy_right);
	vals[B] = -2 * dot(cy_right, c_q);
	vals[C] = dot(c_q, c_q) - cy->radius * cy->radius;
	vals[RES] = solve_quadratic(vals);
	if (vals[RES] >= 0 && (hit->closest == -1 || vals[RES] < hit->closest))
	{
		hit->closest = vals[RES];
		scalar_op(&hit->hitp, &ray.orient, '*', vals[RES]);
		vector_op(&hit->hitp, &hit->hitp, '+', &ray.origin);
		copy_vector(&hit->color, &cy->color);
		cross_vector(&hit->normal, c_q, cy->orient);
		cross_vector(&hit->normal, hit->normal, cy->orient);
		normalize(&hit->normal);
		hit->obj = cy;
		return (1);
	}
	return (0);
}
