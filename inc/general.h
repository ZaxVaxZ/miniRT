/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:34:14 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/14 11:38:57 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
# include "mlx.h"

# define HEIGHT 512
# define WIDTH 1024
# define ESC 53
# define SUCCESS 0
# define FAILURE 1
# define ERR_MEM 2

typedef struct	s_main
{
	void	*mlx;
	void	*mw;
	void	*img;
	char	*pixel;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_main;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	float	a;
}	t_vector;

typedef struct s_matrix_2d
{
	int		rows;
	int		cols;
	float	**array;
}	t_matrix_2d;

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


void	free_and_exit(t_main *m, int msg, int status);

#endif