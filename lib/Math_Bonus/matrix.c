/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:28 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/10 16:10:28 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_matrix_2d	*cross_matrix(const t_matrix_2d *m1, const t_matrix_2d *m2)
{
	int			i;
	int			ri;
	int			rj;
	t_matrix_2d	*result;

	if (!m1 || !m2 || !m1->array || !m2->array || m1->cols != m2->rows)
		return (NULL);
	result = malloc(sizeof(t_matrix_2d));
	if (!result)
		return (NULL);
	if (create_matrix(result, m1->rows, m2->cols))
		return (NULL);
	ri = 0;
	rj = 0;
	while (ri < result->rows)
	{
		i = -1;
		while (++i < m1->cols)
			result->array[ri][rj] += m1->array[ri][i] * m2->array[i][rj];
		rj++;
		ri += (rj >= result->cols);
		rj *= (rj < result->cols);
	}
	return (result);
}

int	create_matrix(t_matrix_2d *m, int rows, int cols)
{
	int	i;
	int	j;

	m->rows = rows;
	m->cols = cols;
	m->array = malloc((m->rows) * sizeof(double *));
	if (!m->array)
		return (-1);
	i = -1;
	while (++i < m->rows)
	{
		m->array[i] = malloc(m->cols * sizeof(double));
		if (!m->array[i])
		{
			free_matrix(m);
			return (-1);
		}
		j = -1;
		while (++j < m->cols)
			m->array[i][j] = 0;
	}
	return (0);
}

int	copy_matrix(t_matrix_2d *dest, const t_matrix_2d *src)
{
	int	i;
	int	j;
	int	ret;

	if (!dest || !src || !src->array)
		return (1);
	ret = create_matrix(dest, src->rows, src->cols);
	if (ret)
		return (ret);
	dest->rows = src->rows;
	dest->cols = src->cols;
	i = 0;
	while (i < src->rows)
	{
		j = -1;
		while (++j < src->cols)
			dest->array[i][j] = src->array[i][j];
		i++;
	}
	return (0);
}

void	transform_vector(t_matrix_2d *m, t_vector *v, int is_point)
{
	int		i;
	int		j;
	double	res[4];

	v->quat[0] = v->x;
	v->quat[1] = v->y;
	v->quat[2] = v->z;
	v->quat[3] = is_point;
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[3] = 0;
	i = -1;
	while (++i < m->rows)
	{
		j = -1;
		while (++j < m->cols)
			res[i] += m->array[i][j] * v->quat[j];
	}
	v->x = res[0];
	v->y = res[1];
	v->z = res[2];
}
