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
	o->origin.x = vals[i++];
	o->origin.y = vals[i++];
	o->origin.z = vals[i++];
	o->orient.x = vals[i++];
	o->orient.y = vals[i++];
	o->orient.z = vals[i++];
	o->fov = vals[i++];
}

void	read_light_values(t_light *c, double *vals)
{
	int	i;

	i = 0;
	o->is_ambient = (vals[i++] == AMBIENT);
	o->origin.x = vals[i++];
	o->origin.y = vals[i++];
	o->origin.z = vals[i++];
	i += 3;
	o->brightness = vals[i++];
	i++;
	o->color.x = vals[i++];
	o->color.y = vals[i++];
	o->color.z = vals[i++];
}

void	read_shape_values(t_object *o, double *vals)
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
		free_and_exit()
	o->trans_matrix[0][0] = 1;
	o->trans_matrix[1][1] = 1;
	o->trans_matrix[2][2] = 1;
	o->trans_matrix[3][3] = 1;
}
