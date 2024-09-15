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

void	read_camera_values(t_camera *c, double *vals)
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
}

void	read_light_values(t_light *li, double *vals)
{
	int	i;

	i = 0;
	li->is_ambient = (vals[i++] == AMBIENT);
	li->origin.x = vals[i++];
	li->origin.y = vals[i++];
	li->origin.z = vals[i++];
	i += 3;
	li->brightness = vals[i++];
	i++;
	li->color.x = vals[i++];
	li->color.y = vals[i++];
	li->color.z = vals[i++];
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
	o->radius = vals[i++];
	o->height = vals[i++];
	o->color.x = vals[i++];
	o->color.y = vals[i++];
	o->color.z = vals[i++];
	if (create_matrix(&o->trans_matrix, 4, 4))
		free_and_exit(m, "Memory allocation failed", EXIT_FAILURE);
	o->trans_matrix.array[0][0] = 1;
	o->trans_matrix.array[1][1] = 1;
	o->trans_matrix.array[2][2] = 1;
	o->trans_matrix.array[3][3] = 1;
}
