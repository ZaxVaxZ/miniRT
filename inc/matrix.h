/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:47 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/10 16:10:47 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include "general.h"

t_matrix_2d	*cross_matrix(const t_matrix_2d *m1, const t_matrix_2d *m2);
void		free_matrix(t_matrix_2d *m);
int			create_matrix(t_matrix_2d *m, int rows, int cols);
int			copy_matrix(t_matrix_2d *dest, const t_matrix_2d *src);

#endif