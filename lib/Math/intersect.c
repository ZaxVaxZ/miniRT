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
	vals[RESULT] = (-vals[B] - sqrt(vals[DISC])) / (2 * vals[A]);
	tmp = (-vals[B] + sqrt(vals[DISC])) / (2 * vals[A]);
	if (vals[RESULT] <= 0 || tmp < vals[RESULT])
		vals[RESULT] = tmp;
	return (vals[RESULT]);
}

void	hit_sphere(t_camera *c, t_ray ray, t_object sp, t_hit *hit)
{
	double		vals[5];
	t_vector	C_Q;

	transform_vector(&c->trans_matrix, &sp.origin, 1);
	vals[A] = dot(ray.orient, ray.orient);
	vector_op(&C_Q, &sp.origin, '-', &ray.origin);
	vals[B] = -2.0 * dot(ray.orient, C_Q);
	vals[C] = dot(C_Q, C_Q) - sp.radius * sp.radius;
	vals[RESULT] = solve_quadratic(vals);
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

void	hit_plane(t_camera *c, t_ray ray, t_object pl, t_hit *hit)
{
	t_vector	tmp;
	double		result;
	double		denominator;

	transform_vector(&c->trans_matrix, &pl.origin, 1);
	transform_vector(&c->trans_matrix, &pl.orient, 0);
	denominator = dot(pl.orient, ray.orient);
	if (denominator >= -1e-6 && denominator <= 1e-6)
		return ;
	vector_op(&tmp, &pl.origin, '-', &ray.origin);
	result = dot(tmp, pl.orient) / denominator;
	if (result < 1e-6)
		return ;
	if (hit->closest == -1 || result < hit->closest)
	{
		hit->closest = result;
		scalar_op(&hit->hitp, &ray.orient, '*', result);
		vector_op(&hit->hitp, &ray.orient, '+', &ray.origin);
		copy_vector(&hit->color, &pl.color);
		copy_vector(&hit->normal, &pl.orient);
	}
}

void	hit_cylinder(t_camera *c, t_ray ray, t_object cy, t_hit *hit)
{
	double		vals[5];
	t_vector	cy_right;
	t_vector	C_Q;

	transform_vector(&c->trans_matrix, &cy.origin, 1);
	transform_vector(&c->trans_matrix, &cy.orient, 0);
	cross_vector(&cy_right, ray.orient, cy.orient);
	vector_op(&C_Q, &cy.origin, '-', &ray.origin);
	cross_vector(&C_Q, C_Q, cy.orient);
	vals[A] = dot(cy_right, cy_right);
	vals[B] = -2 * dot(cy_right, C_Q);
	vals[C] = dot(C_Q, C_Q) - cy.radius * cy.radius;
	vals[RESULT] = solve_quadratic(vals);
	if (vals[RESULT] >= 0 && (hit->closest == -1 || vals[RESULT] < hit->closest))
	{
		hit->closest = vals[RESULT];
		scalar_op(&hit->hitp, &ray.orient, '*', vals[RESULT]);
		vector_op(&hit->hitp, &ray.orient, '+', &ray.origin);
		copy_vector(&hit->color, &cy.color);
		cross_vector(&hit->normal, C_Q, cy.orient);
		cross_vector(&hit->normal, hit->normal, cy.orient);
		normalize(&hit->normal);
	}
}

void	hit_cone(t_camera *c, t_ray ray, t_object co, t_hit *hit)
{
	double		vals[5];
	t_vector	C_Q;

	transform_vector(&c->trans_matrix, &co.origin, 1);
	transform_vector(&c->trans_matrix, &co.orient, 0);
	vals[A] = dot(ray.orient, ray.orient);
	vector_op(&C_Q, &co.origin, '-', &ray.origin);
	vals[B] = 2 * dot(ray.orient, C_Q);
	vals[C] = dot(C_Q, C_Q) - co.radius * co.radius;
	vals[RESULT] = solve_quadratic(vals);
	if (hit->closest == -1 || vals[RESULT] < hit->closest)
	{
		hit->closest = vals[RESULT];
	}
}
