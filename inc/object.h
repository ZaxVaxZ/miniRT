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

t_object	*cross_matrix(const t_object *m1, const t_object *m2);
void		free_matrix(t_object *m);
int			create_matrix(t_object *m, int rows, int cols);
int			copy_matrix(t_object *dest, const t_object *src);

#endif