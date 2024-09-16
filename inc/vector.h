/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:42 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/10 16:10:42 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>
# include "general.h"

double	dot(t_vector v1, t_vector v2);
double	magnitude(t_vector v);
void	cross_vector(t_vector *result, t_vector v1, t_vector v2);
void	copy_vector(t_vector *dest, const t_vector *src);

#endif