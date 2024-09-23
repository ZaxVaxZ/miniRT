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

void	scale_and_translate(t_object *o)
{
	o->trans_matrix.array[0][3] = o->origin.x;
	o->trans_matrix.array[1][3] = o->origin.y;
	o->trans_matrix.array[2][3] = o->origin.z;
	assign(&o->origin, 0, 0, 0);
	if (o->object_type != PLANE)
	{
		o->trans_matrix.array[0][0] *= o->radius;
		o->trans_matrix.array[2][2] *= o->radius;
	}
	if (o->object_type == SPHERE)
		o->trans_matrix.array[1][1] *= o->radius;
	if (o->object_type == CYLINDER || o->object_type == CONE)
		o->trans_matrix.array[1][1] *= o->height;
	o->radius = 1;
	o->height = 1;
}

void	rotation_and_inverse(t_object *o)
{
	double		d;
	t_vector	default_v;

	assign(&default_v, 0, 0, 1);
	d = dot(o->orient, default_v);
	if (is_equal(d, 1))
		return ;
	cross_vector(&default_v, &o->orient, &default_v);
	normalize(&default_v);
	
}

void	setup_transform_obj(t_object *o)
{
	
}

void	setup_transform_cam(t_object *o)
{

}

void	setup_transform_light(t_object *o)
{

}