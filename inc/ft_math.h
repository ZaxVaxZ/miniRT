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

t_matrix_2d	*cross_matrix(const t_matrix_2d *m1, const t_matrix_2d *m2);
void		free_matrix(t_matrix_2d *m);
int			create_matrix(t_matrix_2d *m, int rows, int cols);
int			copy_matrix(t_matrix_2d *dest, const t_matrix_2d *src);
void		cross_vector(t_vector *result, t_vector v1, t_vector v2);
void		scalar_op(t_vector *res, t_vector *v, char op, double value);
void		vector_op(t_vector *res, t_vector *v1, char op, t_vector *v2);
void		assign(t_vector *v, double x, double y, double z);
double		dot(t_vector v1, t_vector v2);
double		intersect_sphere(t_ray *ray, t_object *sp, double *ret);

#endif