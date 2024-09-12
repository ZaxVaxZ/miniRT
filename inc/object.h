/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:15:36 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/10 16:15:36 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdlib.h>
# include "matrix.h"
# include "vector.h"

typedef enum e_object_type
{
	Plane,
	Sphere,
	Cone
}	t_object_type;

typedef struct s_object
{
	float			radius;
	float			height;
	t_vector		origin;
	t_matrix_2d		trans;
	t_object_type	type;
}	t_object;

typedef struct s_camera
{
	float		focal_length;
	float		fov;
	t_vector	origin;
	t_vector	direct;
	t_matrix_2d	world;
}	t_camera;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direct;
}	t_ray;

#endif