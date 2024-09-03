/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:04:51 by marvin            #+#    #+#             */
/*   Updated: 2024/09/04 00:04:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix_2d
{
	int		rows;
	int		cols;
	float	**array;
}	t_matrix_2d;

t_matrix_2d	*cross_matrix(const t_matrix_2d *m1, const t_matrix_2d *m2);
void		free_matrix(t_matrix_2d *m);
int			create_matrix(t_matrix_2d *m, int rows, int cols);
int			copy_matrix(t_matrix_2d *dest, const t_matrix_2d *src);

#endif