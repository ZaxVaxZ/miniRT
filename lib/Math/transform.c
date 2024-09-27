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
		c->trans_matrix.array[0][3] = c->origin.x;
		c->trans_matrix.array[1][3] = c->origin.y;
		c->trans_matrix.array[2][3] = c->origin.z;
		// c->trans_matrix.array[0][3] = -c->origin.x * c->trans_matrix.array[0][0] + -c->origin.y * c->trans_matrix.array[0][1] + -c->origin.z * c->trans_matrix.array[0][2];
		// c->trans_matrix.array[1][3] = -c->origin.x * c->trans_matrix.array[1][0] + -c->origin.y * c->trans_matrix.array[1][1] + -c->origin.z * c->trans_matrix.array[1][2];
		// c->trans_matrix.array[2][3] = -c->origin.x * c->trans_matrix.array[2][0] + -c->origin.y * c->trans_matrix.array[2][1] + -c->origin.z * c->trans_matrix.array[2][2];
		assign(&c->origin, 0, 0, 0);
	}
}

void	quaternion_to_matrix(t_matrix_2d *m, t_vector *v)
{
	double		q[4];

	q[0] = v->quat[0];
	q[1] = -v->quat[1];
	q[2] = -v->quat[2];
	q[3] = -v->quat[3];
	m->array[0][0] = 2 * (q[0] * q[0] + q[1] * q[1]) - 1;
	m->array[0][1] = 2 * (q[1] * q[2] - q[0] * q[3]);
	m->array[0][2] = 2 * (q[1] * q[3] + q[0] * q[2]);
	m->array[1][0] = 2 * (q[1] * q[2] + q[0] * q[3]);
	m->array[1][1] = 2 * (q[0] * q[0] + q[2] * q[2]) - 1;
	m->array[1][2] = 2 * (q[2] * q[3] - q[0] * q[1]);
	m->array[2][0] = 2 * (q[1] * q[3] - q[0] * q[2]);
	m->array[2][1] = 2 * (q[2] * q[3] + q[0] * q[1]);
	m->array[2][2] = 2 * (q[0] * q[0] + q[3] * q[3]) - 1;
}

void	camera_look_at(t_camera *c)
{
	c->trans_matrix.array[0][0] = c->right.x;
	c->trans_matrix.array[0][1] = c->right.y;
	c->trans_matrix.array[0][2] = c->right.z;
	c->trans_matrix.array[1][0] = c->up.x;
	c->trans_matrix.array[1][1] = c->up.y;
	c->trans_matrix.array[1][2] = c->up.z;
	c->trans_matrix.array[2][0] = c->orient.x;
	c->trans_matrix.array[2][1] = c->orient.y;
	c->trans_matrix.array[2][2] = c->orient.z;
	c->trans_matrix.array[0][3] = -dot(c->right, c->origin);
	c->trans_matrix.array[1][3] = -dot(c->up, c->origin);
	c->trans_matrix.array[2][3] = dot(c->orient, c->origin);
	assign(&c->origin, 0, 0, 0);
}
// static t_matrix4	camera_look_at(t_vector3f eye,
// 								t_vector3f center,
// 								t_vector3f up)
// {
// 	t_vector3f	f;
// 	t_vector3f	s;
// 	t_vector3f	u;
// 	t_matrix4	result;

// 	f = vector3f_unit(vector3f_subtract(center, eye));
// 	s = vector3f_unit(vector3f_cross(f, up));
// 	u = vector3f_cross(s, f);
// 	result = matrix4_create_identity();
// 	result.matrix[0][0] = s.x;
// 	result.matrix[1][0] = s.y;
// 	result.matrix[2][0] = s.z;
// 	result.matrix[0][1] = u.x;
// 	result.matrix[1][1] = u.y;
// 	result.matrix[2][1] = u.z;
// 	result.matrix[0][2] = -f.x;
// 	result.matrix[1][2] = -f.y;
// 	result.matrix[2][2] = -f.z;
// 	result.matrix[3][0] = -vector3f_dot(s, eye);
// 	result.matrix[3][1] = -vector3f_dot(u, eye);
// 	result.matrix[3][2] = vector3f_dot(f, eye);
// 	return (result);
// }

void	rotation_camera_z(t_camera *c)
{
	// double		theta;
	// t_vector	default_orient;
	// t_vector	rot_axis;
(void)quaternion_to_matrix;
	c->trans_matrix.array[0][0] = c->right.x;
	c->trans_matrix.array[1][0] = c->right.y;
	c->trans_matrix.array[2][0] = c->right.z;
	c->trans_matrix.array[0][1] = c->up.x;
	c->trans_matrix.array[1][1] = c->up.y;
	c->trans_matrix.array[2][1] = c->up.z;
	c->trans_matrix.array[0][2] = c->orient.x;
	c->trans_matrix.array[1][2] = c->orient.y;
	c->trans_matrix.array[2][2] = c->orient.z;
	// for(int i=0;i<3;i++)
	// 	printf("%lf, %lf, %lf\n", c->trans_matrix.array[i][0], c->trans_matrix.array[i][1], c->trans_matrix.array[i][2]);
	// assign(&default_orient, 0, 0, -1);
	// theta = acos(dot(c->orient, default_orient));
	// cross_vector(&rot_axis, default_orient, c->orient);
	// normalize(&rot_axis);
	// c->orient.quat[0] = cos(theta / 2.0);
	// c->orient.quat[1] = rot_axis.x * sin(theta / 2.0);
	// c->orient.quat[2] = rot_axis.y * sin(theta / 2.0);
	// c->orient.quat[3] = 0;
	// quaternion_to_matrix(&c->trans_matrix, &c->orient);
	assign(&c->orient, 0, 0, -1);
}

void	rotation_camera_y(t_main *m, t_camera *c)
{
	double		theta;
	t_vector	default_orient;
	t_vector	rot_axis;
	t_matrix_2d	tmp;
	t_matrix_2d	*ret;

	assign(&default_orient, 0, 1, 0);
	theta = acos(dot(c->orient, default_orient));
	cross_vector(&rot_axis, default_orient, c->orient);
	c->orient.quat[0] = cos(theta / 2.0);
	c->orient.quat[1] = rot_axis.x * sin(theta / 2.0);
	c->orient.quat[2] = rot_axis.y * sin(theta / 2.0);
	c->orient.quat[3] = rot_axis.z * sin(theta / 2.0);
	if (copy_matrix(&tmp, &c->trans_matrix))
		free_and_exit(m, ERR_MEM, 1);
	(void)ret;
	quaternion_to_matrix(&tmp, &c->orient);
	ret = cross_matrix(&tmp, &c->trans_matrix);
	if (!ret)
	{
		free_matrix(&tmp);
		free_and_exit(m, ERR_MEM, 1);
	}
	free_matrix(&c->trans_matrix);
	copy_matrix(&c->trans_matrix, ret);
	free_matrix(&tmp);
	free_matrix(ret);
	free(ret);
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
