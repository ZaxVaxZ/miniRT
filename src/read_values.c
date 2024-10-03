/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:20:42 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 16:20:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	read_camera_values(t_main *m, t_camera *c, double *vals)
{
	int	i;

	i = 1;
	c->origin.x = vals[i++];
	c->origin.y = vals[i++];
	c->origin.z = vals[i++];
	c->orient.x = vals[i++];
	c->orient.y = vals[i++];
	c->orient.z = vals[i++];
	c->fov = vals[i++];
	if (create_matrix(&c->trans_matrix, 4, 4))
		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
	c->trans_matrix.array[3][3] = 1;
	scalar_op(&c->origin, &c->origin, '*', -1);
	scalar_op(&c->orient, &c->orient, '*', -1);
	get_up_vector(c);
	camera_look_at(c);
	assign(&c->orient, 0, 0, -1);
}

void	read_light_values(t_main *m, t_light *li, double *vals)
{
	int	i;

	i = 0;
	li->is_ambient = is_equal(vals[i++], AMBIENT);
	li->origin.x = vals[i++];
	li->origin.y = vals[i++];
	li->origin.z = vals[i++];
	i += 3;
	li->brightness = vals[i++];
	i++;
	li->color.x = vals[i++];
	li->color.y = vals[i++];
	li->color.z = vals[i++];
	transform_vector(&m->scene.camera.trans_matrix, &li->origin, 1);
}

void	read_shape_values(t_main *m, t_object *o, double *vals)
{
	int	i;

	i = 0;
	o->object_type = vals[i++];
	o->origin.x = vals[i++];
	o->origin.y = vals[i++];
	o->origin.z = vals[i++];
	o->orient.x = vals[i++];
	o->orient.y = vals[i++];
	o->orient.z = vals[i++];
	o->radius = vals[i++] / 2.0;
	o->height = vals[i++];
	if (o->object_type == SPHERE)
		o->height = o->radius;
	o->color.x = vals[i++];
	o->color.y = vals[i++];
	o->color.z = vals[i++];
	if (create_matrix(&o->trans_matrix, 4, 4))
		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
	o->trans_matrix.array[0][0] = 1;
	o->trans_matrix.array[1][1] = 1;
	o->trans_matrix.array[2][2] = 1;
	o->trans_matrix.array[3][3] = 1;
	transform_vector(&m->scene.camera.trans_matrix, &o->origin, 1);
	transform_vector(&m->scene.camera.trans_matrix, &o->orient, 0);
}

void	count_shapes(int count[4], double **objs)
{
	int	i;

	i = -1;
	while (++i < 4)
		count[i] = 0;
	if (!objs || !objs[0])
		return ;
	i = -1;
	while (objs[++i][0] != INVALID)
	{
		count[CONE] += is_equal(objs[i][0], CONE);
		count[PLANE] += is_equal(objs[i][0], PLANE);
		count[SPHERE] += is_equal(objs[i][0], SPHERE);
		count[CYLINDER] += is_equal(objs[i][0], CYLINDER);
	}
}
