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
