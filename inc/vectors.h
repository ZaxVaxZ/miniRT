/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:53:40 by marvin            #+#    #+#             */
/*   Updated: 2024/09/03 15:53:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

#include <math.h>

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	float	a;
}	t_vector;

float	dot(t_vector v1, t_vector v2);
float	magnitude(t_vector v);
void	cross_vector(t_vector *result, t_vector v1, t_vector v2);
void	copy_vector(t_vector *dest, const t_vector *src);

#endif