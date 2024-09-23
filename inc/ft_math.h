/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:10:35 by marvin            #+#    #+#             */
/*   Updated: 2024/09/17 17:10:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>
# include <stdlib.h>
# include "general.h"

# define A 0
# define B 1
# define C 2
# define DISC 3
# define RESULT 4

t_matrix_2d	*cross_matrix(const t_matrix_2d *m1, const t_matrix_2d *m2);
void		free_matrix(t_matrix_2d *m);
int			create_matrix(t_matrix_2d *m, int rows, int cols);
int			copy_matrix(t_matrix_2d *dest, const t_matrix_2d *src);
void		cross_vector(t_vector *result, t_vector v1, t_vector v2);
void		scalar_op(t_vector *res, t_vector *v, char op, double value);
void		vector_op(t_vector *res, t_vector *v1, char op, t_vector *v2);
void		assign(t_vector *v, double x, double y, double z);
void		normal_at(t_ray *ray, t_hit *hit, double t);
void		hit_sphere(t_ray *ray, t_object *sp, t_hit *hit);
void		hit_cone(t_ray *ray, t_object *sp, t_hit *hit);
void		hit_cylinder(t_ray *ray, t_object *sp, t_hit *hit);
void		hit_plane(t_ray *ray, t_object *sp, t_hit *hit);
void		normalize(t_vector *v);
int			is_equal(double x, double y);
double		dot(t_vector v1, t_vector v2);
void		copy_vector(t_vector *v1, t_vector *v2);

#endif