/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:41:26 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 22:41:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	is_equal(double x, double y)
{
	return (-1e-6 + y <= x && x <= y + 1e-6);
}

void	normalize(t_vector *v)
{
	double	len;

	len = sqrt(dot(*v, *v));
	v->x /= len;
	v->y /= len;
	v->z /= len;
}

void	copy_vector(t_vector *v1, t_vector *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = v2->z;
}

void	get_up_vector(t_camera *c)
{
	t_vector	world_up;

	assign(&world_up, 0, 1, 0);
	normalize(&c->orient);
	if (is_equal(c->orient.x, 0) && is_equal(c->orient.z, 0))
		assign(&c->right, 1, 0, 0);
	else
		cross_vector(&c->right, c->orient, world_up);
	normalize(&c->right);
	cross_vector(&c->up, c->right, c->orient);
	normalize(&c->up);
}
