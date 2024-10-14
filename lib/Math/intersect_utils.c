/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:59:00 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 20:59:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	valid_hit(t_object *cy, t_ray ray, t_hit *hit, double ret)
{
	t_point	hitp;
	t_point	diff;
	double	dist;

	scalar_op(&hitp, &ray.orient, '*', ret);
	vector_op(&hitp, &hitp, '+', &ray.origin);
	vector_op(&diff, &hitp, '-', &cy->origin);
	dist = dot(diff, cy->orient);
	if (dist > 0.5 * cy->height || dist < -0.5 * cy->height)
		return (0);
	return (hit->closest == -1 || ret < hit->closest);
}

int	intersect_cap(t_object *pl, t_hit *hit, t_ray *ray)
{
	double	result;
	double	denominator;
	t_point	hitp;
	t_point	diff;

	denominator = dot(pl->orient, ray->orient);
	if (denominator >= -1e-6 && denominator <= 1e-6)
		return (0);
	vector_op(&diff, &pl->origin, '-', &ray->origin);
	result = dot(diff, pl->orient) / denominator;
	if (result < 1e-6)
		return (0);
	scalar_op(&hitp, &ray->orient, '*', result);
	vector_op(&hitp, &hitp, '+', &ray->origin);
	vector_op(&diff, &hitp, '-', &pl->origin);
	if ((dot(diff, diff) >= pl->radius * pl->radius)
		|| (hit->closest > -1 && hit->closest <= result))
		return (0);
	hit->closest = result;
	copy_vector(&hit->hitp, &hitp);
	copy_vector(&hit->color, &pl->color);
	copy_vector(&hit->normal, &pl->orient);
	if (dot(hit->normal, ray->orient) > 0)
		scalar_op(&hit->normal, &hit->normal, '*', -1);
	return (1);
}

int	cy_cap_intersect(t_object *cy, t_ray *ray, t_hit *hit)
{
	int			ret;
	t_object	pl_top;
	t_object	pl_bot;

	normalize(&cy->orient);
	pl_top.radius = cy->radius;
	pl_bot.radius = cy->radius;
	copy_vector(&pl_top.orient, &cy->orient);
	scalar_op(&pl_top.origin, &cy->orient, '*', 0.5 * cy->height);
	vector_op(&pl_top.origin, &pl_top.origin, '+', &cy->origin);
	scalar_op(&pl_bot.orient, &cy->orient, '*', -1);
	scalar_op(&pl_bot.origin, &cy->orient, '*', -0.5 * cy->height);
	vector_op(&pl_bot.origin, &pl_bot.origin, '+', &cy->origin);
	copy_vector(&pl_top.color, &cy->color);
	copy_vector(&pl_bot.color, &cy->color);
	ret = intersect_cap(&pl_top, hit, ray);
	ret += intersect_cap(&pl_bot, hit, ray);
	return (ret > 0);
}

int	save_result(t_object *obj, t_ray ray, t_hit *hit, double result)
{
	t_vector	c_q;

	hit->closest = result;
	scalar_op(&hit->hitp, &ray.orient, '*', result);
	vector_op(&hit->hitp, &hit->hitp, '+', &ray.origin);
	vector_op(&c_q, &hit->hitp, '-', &obj->origin);
	copy_vector(&hit->color, &obj->color);
	if (obj->object_type == CYLINDER)
	{
		cross_vector(&hit->normal, c_q, obj->orient);
		cross_vector(&hit->normal, hit->normal, obj->orient);
	}
	else if (obj->object_type == SPHERE)
		vector_op(&hit->normal, &hit->hitp, '-', &obj->origin);
	else if (obj->object_type == PLANE)
		copy_vector(&hit->normal, &obj->orient);
	normalize(&hit->normal);
	if (dot(hit->normal, ray.orient) > 0)
		scalar_op(&hit->normal, &hit->normal, '*', -1);
	hit->obj = obj;
	return (1);
}
