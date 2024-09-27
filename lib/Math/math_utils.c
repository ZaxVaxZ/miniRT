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

double	magnitude(t_vector v)
{
	return (sqrt(dot(v, v)));
}

void	get_up_vector(t_camera *c)
{
	t_vector	up;
	// t_vector	right;
	t_vector x = (t_vector){1, 0, 0, {0, 0, 0, 0}};
	t_vector z = (t_vector){0, 0, 1, {0, 0, 0, 0}};

	assign(&up, 0, 1, 0);
	normalize(&c->orient);
	cross_vector(&c->right, c->orient, up);
	normalize(&c->right);
	printf("right.up (0): %lf\n", dot(c->right, up));
	printf("right.z (positive): %lf\n", dot(c->right, z));
	printf("right.x (positive): %lf\n", dot(c->right, x));
	cross_vector(&c->up, c->right, c->orient);
	normalize(&c->up);
	printf("cup.up (positive): %lf\n", dot(c->up, up));
}
