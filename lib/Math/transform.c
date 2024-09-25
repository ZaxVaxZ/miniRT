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

// static void	scale_object(t_main *m, t_object *o)
// {
// 	t_matrix_2d	tmp;
// 	t_matrix_2d	scale;

// 	if (create_matrix(&scale, 4, 4))
// 		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
// 	scale.array[0][0] = 1;
// 	scale.array[1][1] = 1;
// 	scale.array[2][2] = 1;
// 	scale.array[3][3] = 1;
// 	if (o->object_type != PLANE)
// 	{
// 		scale.array[0][0] = o->radius;
// 		scale.array[1][1] = o->height;
// 		scale.array[2][2] = o->radius;
// 	}
// 	if (copy_matrix(&tmp, &o->trans_matrix))
// 	{
// 		free_matrix(&scale);
// 		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
// 	}
// 	o->trans_matrix = cross_matrix(&scale, &tmp);
// 	free_matrix(&tmp);
// 	free_matrix(&scale);
// 	if (!(o->trans_matrix))
// 		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
// }

void	scale_and_translate(t_main *m, t_object *o, t_camera *c)
{
		(void)m;
	if (o)
	{
		// scale_object(m, o);
		o->trans_matrix.array[0][3] = -o->origin.x;
		o->trans_matrix.array[1][3] = -o->origin.y;
		o->trans_matrix.array[2][3] = -o->origin.z;
		// o->trans_matrix.array[0][3] = -o->origin.x * o->trans_matrix.array[0][0] + -o->origin.y * o->trans_matrix.array[0][1] + -o->origin.z * o->trans_matrix.array[0][2];
		// o->trans_matrix.array[1][3] = -o->origin.x * o->trans_matrix.array[1][0] + -o->origin.y * o->trans_matrix.array[1][1] + -o->origin.z * o->trans_matrix.array[1][2];
		// o->trans_matrix.array[2][3] = -o->origin.x * o->trans_matrix.array[2][0] + -o->origin.y * o->trans_matrix.array[2][1] + -o->origin.z * o->trans_matrix.array[2][2];
		// assign(&o->origin, 0, 0, 0);
		
		// for(int i=0;i<4;i++)
		// 	printf("%lf, %lf, %lf, %lf\n", o->trans_matrix.array[i][0], o->trans_matrix.array[i][1], o->trans_matrix.array[i][2], o->trans_matrix.array[i][3]);
		// o->radius = 1;
		// o->height = 1;
	}
	if (c)
	{
		// c->trans_matrix.array[0][3] = c->origin.x;
		// c->trans_matrix.array[1][3] = c->origin.y;
		// c->trans_matrix.array[2][3] = c->origin.z;
		c->trans_matrix.array[0][3] = -c->origin.x * c->trans_matrix.array[0][0] + -c->origin.y * c->trans_matrix.array[0][1] + -c->origin.z * c->trans_matrix.array[0][2];
		c->trans_matrix.array[1][3] = -c->origin.x * c->trans_matrix.array[1][0] + -c->origin.y * c->trans_matrix.array[1][1] + -c->origin.z * c->trans_matrix.array[1][2];
		c->trans_matrix.array[2][3] = -c->origin.x * c->trans_matrix.array[2][0] + -c->origin.y * c->trans_matrix.array[2][1] + -c->origin.z * c->trans_matrix.array[2][2];
		assign(&c->origin, 0, 0, 0);
	}
}

void	rotation_camera(t_camera *c)
{
	double		q[4];
	double		theta;
	t_vector	default_orient;
	t_vector	rot_axis;

	normalize(&c->orient);
	assign(&default_orient, 0, 0, -1);
	theta = acos(dot(c->orient, default_orient));
	cross_vector(&rot_axis, default_orient, c->orient);
	c->orient.quat[0] = cos(theta / 2.0);
	c->orient.quat[1] = rot_axis.x * sin(theta / 2.0);
	c->orient.quat[2] = rot_axis.y * sin(theta / 2.0);
	c->orient.quat[3] = rot_axis.z * sin(theta / 2.0);
	q[0] = c->orient.quat[0];
	q[1] = -c->orient.quat[1];
	q[2] = -c->orient.quat[2];
	q[3] = -c->orient.quat[3];
	c->trans_matrix.array[0][0] = 2 * (q[0] * q[0] + q[1] * q[1]) - 1;
	c->trans_matrix.array[0][1] = 2 * (q[1] * q[2] - q[0] * q[3]);
	c->trans_matrix.array[0][2] = 2 * (q[1] * q[3] + q[0] * q[2]);
	c->trans_matrix.array[1][0] = 2 * (q[1] * q[2] + q[0] * q[3]);
	c->trans_matrix.array[1][1] = 2 * (q[0] * q[0] + q[2] * q[2]) - 1;
	c->trans_matrix.array[1][2] = 2 * (q[2] * q[3] - q[0] * q[1]);
	c->trans_matrix.array[2][0] = 2 * (q[1] * q[3] - q[0] * q[2]);
	c->trans_matrix.array[2][1] = 2 * (q[2] * q[3] + q[0] * q[1]);
	c->trans_matrix.array[2][2] = 2 * (q[0] * q[0] + q[3] * q[3]) - 1;
	// c->trans_matrix.array[0][0] = 1 - 2 * (q[2] * q[2] + q[3] * q[3]);
	// c->trans_matrix.array[0][1] = 2 * (q[1] * q[2] - q[0] * q[3]);
	// c->trans_matrix.array[0][2] = 2 * (q[1] * q[3] + q[0] * q[2]);
	// c->trans_matrix.array[1][0] = 2 * (q[1] * q[2] + q[0] * q[3]);
	// c->trans_matrix.array[1][1] = 1 - 2 * (q[1] * q[1] + q[3] * q[3]);
	// c->trans_matrix.array[1][2] = 2 * (q[2] * q[3] - q[0] * q[1]);
	// c->trans_matrix.array[2][0] = 2 * (q[1] * q[3] - q[0] * q[2]);
	// c->trans_matrix.array[2][1] = 2 * (q[2] * q[3] + q[0] * q[1]);
	// c->trans_matrix.array[2][2] = 1 - 2 * (q[0] * q[0] + q[2] * q[2]);
	assign(&c->orient, 0, 0, -1);
}

void	rotation_object(t_object *o)
{
	double		q[4];
	double		theta;
	t_vector	default_orient;
	t_vector	rot_axis;

	normalize(&o->orient);
	assign(&default_orient, 0, 0, 1);
	theta = acos(dot(o->orient, default_orient));
	cross_vector(&rot_axis, default_orient, o->orient);
	o->orient.quat[0] = cos(theta / 2.0);
	o->orient.quat[1] = rot_axis.x * sin(theta / 2.0);
	o->orient.quat[2] = rot_axis.y * sin(theta / 2.0);
	o->orient.quat[3] = rot_axis.z * sin(theta / 2.0);
	q[0] = o->orient.quat[0];
	q[1] = o->orient.quat[1];
	q[2] = o->orient.quat[2];
	q[3] = o->orient.quat[3];
	o->trans_matrix.array[0][0] = 1 - 2 * (q[2] * q[2] + q[3] * q[3]);
	o->trans_matrix.array[0][1] = 2 * (q[1] * q[2] - q[0] * q[3]);
	o->trans_matrix.array[0][2] = 2 * (q[1] * q[3] + q[0] * q[2]);
	o->trans_matrix.array[1][0] = 2 * (q[1] * q[2] + q[0] * q[3]);
	o->trans_matrix.array[1][1] = 1 - 2 * (q[1] * q[1] + q[3] * q[3]);
	o->trans_matrix.array[1][2] = 2 * (q[2] * q[3] - q[0] * q[1]);
	o->trans_matrix.array[2][0] = 2 * (q[1] * q[3] - q[0] * q[2]);
	o->trans_matrix.array[2][1] = 2 * (q[2] * q[3] + q[0] * q[1]);
	o->trans_matrix.array[2][2] = 1 - 2 * (q[0] * q[0] + q[2] * q[2]);
	assign(&o->orient, 0, 0, 1);
}

void	transform_vector(t_matrix_2d *m, t_vector *v, int is_point)
{
	int		i;
	int		j;
	double	res[4];

	v->quat[0] = v->x;
	v->quat[1] = v->y;
	v->quat[2] = v->z;
	v->quat[3] = is_point;
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[3] = 0;
	i = -1;
	while (++i < m->rows)
	{
		j = -1;
		while (++j < m->cols)
			res[i] += m->array[i][j] * v->quat[j];
	}
	v->x = res[0];
	v->y = res[1];
	v->z = res[2];
}
