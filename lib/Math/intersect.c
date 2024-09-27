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

static void	transform_object(t_camera *c, t_object *o)
{
	transform_vector(&c->trans_matrix, &o->origin, 1);
	// o->origin.x += c->trans_matrix.array[0][3];
	// o->origin.y += c->trans_matrix.array[1][3];
	// o->origin.z += c->trans_matrix.array[2][3];
	if (o->object_type != SPHERE)
		transform_vector(&c->trans_matrix, &o->orient, 0);
}

void	hit_sphere(t_camera *c, t_ray ray, t_object sp, t_hit *hit)
{
	double		vals[5];
	t_vector	C_Q;
(void)c; (void)transform_object;
	// if (hit->i % 100 == 0 && hit->j % 100 == 0)
	// 	printf("o1: %lf, %lf, %lf\n", sp.origin.x, sp.origin.y, sp.origin.z);
	static int pr = 0;
	// if (is_equal(sp.origin.x, 1) && is_equal(sp.origin.y, 1) && is_equal(sp.origin.z, 1))
	if (sp.origin.x == 0)
		pr++;
	transform_object(c, &sp);
	if (pr == 1)
		printf("~ %lf, %lf, %lf\n", sp.origin.x, sp.origin.y, sp.origin.z);
	if (pr)
		pr++;
	// transform_vector(&sp.trans_matrix, &ray.origin, 1);
	// transform_vector(&sp.trans_matrix, &ray.orient, 0);
	// if (hit->i % 100 == 0 && hit->j % 100 == 0)
	// {
	// 	printf("o2: %lf, %lf, %lf\n", sp.origin.x, sp.origin.y, sp.origin.z);
	// 	printf("rayo: %lf, %lf, %lf\n", ray.origin.x, ray.origin.y, ray.origin.z);
	// 	printf("rayd: %lf, %lf, %lf\n", ray.orient.x, ray.orient.y, ray.orient.z);
	// }
	vals[A] = dot(ray.orient, ray.orient);
	vector_op(&C_Q, &sp.origin, '-', &ray.origin);
	vals[B] = -2.0 * dot(ray.orient, C_Q);
	vals[C] = dot(C_Q, C_Q) - sp.radius * sp.radius;
	vals[DISC] = vals[B] * vals[B] - 4.0 * vals[A] * vals[C];
	if (vals[DISC] < 0 || !vals[A])
		return ;
	if ((-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]) > 0)
		vals[RESULT] = (-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]);
	else
		vals[RESULT] = (-vals[B] + sqrt(vals[DISC])) / (2 * vals[A]);
	if (vals[RESULT] >= 0 && (hit->closest == -1 || vals[RESULT] < hit->closest))
	{
		hit->closest = vals[RESULT];
		scalar_op(&hit->hitp, &ray.orient, '*', vals[RESULT]);
		vector_op(&hit->hitp, &ray.orient, '+', &ray.origin);
		copy_vector(&hit->color, &sp.color);
		vector_op(&hit->normal, &hit->hitp, '-', &sp.origin);
		normalize(&hit->normal);
	}
}

void	hit_plane(t_ray *ray, t_object *pl, t_hit *hit)
{
	t_vector	tmp;
	double		result;
	double		denominator;

	denominator = dot(pl->orient, ray->orient);
	if (denominator >= -1e-6 && denominator <= 1e-6)
		return ;
	vector_op(&tmp, &pl->origin, '-', &ray->origin);
	result = dot(tmp, pl->orient) / denominator;
	if (result <= 0)
		return ;
	if (hit->closest == -1 || result < hit->closest)
	{
		hit->obj = pl;
		hit->closest = result;
		scalar_op(&hit->hitp, &ray->orient, '*', result);
		vector_op(&hit->hitp, &ray->orient, '+', &ray->origin);
		copy_vector(&hit->color, &pl->color);
		copy_vector(&hit->normal, &pl->orient);
		// normal_at(ray, hit, result);
	}
}

void	hit_cone(t_ray *ray, t_object *sp, t_hit *hit)
{
	double		vals[5];
	t_vector	C_Q;

	vals[A] = dot(ray->orient, ray->orient);
	vector_op(&C_Q, &sp->origin, '-', &ray->origin);
	vals[B] = 2 * dot(ray->orient, C_Q);
	vals[C] = dot(C_Q, C_Q) - sp->radius * sp->radius;
	vals[DISC] = vals[B] * vals[B] - 4 * vals[A] * vals[C];
	if (vals[DISC] < 0 || !vals[A])
		return ;
	if ((-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]) > 0)
		vals[RESULT] = (-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]);
	else
		vals[RESULT] = (-vals[B] + sqrt(vals[DISC])) / (2 * vals[A]);
	if (hit->closest == -1 || vals[RESULT] < hit->closest)
	{
		hit->closest = vals[RESULT];
		hit->obj = sp;
	}
}

void	hit_cylinder(t_ray *ray, t_object *sp, t_hit *hit)
{
	double		vals[5];
	t_vector	C_Q;

	vals[A] = dot(ray->orient, ray->orient);
	vector_op(&C_Q, &sp->origin, '-', &ray->origin);
	vals[B] = 2 * dot(ray->orient, C_Q);
	vals[C] = dot(C_Q, C_Q) - sp->radius * sp->radius;
	vals[DISC] = vals[B] * vals[B] - 4 * vals[A] * vals[C];
	if (vals[DISC] < 0 || !vals[A])
		return ;
	if ((-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]) > 0)
		vals[RESULT] = (-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]);
	else
		vals[RESULT] = (-vals[B] + sqrt(vals[DISC])) / (2 * vals[A]);
	if (hit->closest == -1 || vals[RESULT] < hit->closest)
	{
		hit->closest = vals[RESULT];
		hit->obj = sp;
	}
}
