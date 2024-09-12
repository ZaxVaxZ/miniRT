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

#include "matrix.h"

t_matrix_2d	*cross_matrix(const t_matrix_2d *m1, const t_matrix_2d *m2)
{
	int		i;
	int		ri;
	int		rj;
	t_matrix_2d	*result;

	if (!m1 || !m2 || !m1->array || !m2->array || m1->cols != m2->rows)
		return (NULL);
	result = malloc(sizeof(t_matrix_2d));
	if (!result)
		return (NULL);
	if (create_matrix(result, m1->rows, m2->cols) < 1)
		return (NULL);
	ri = 0;
	rj = 0;
	i = -1;
	while (ri < result->rows)
	{
		while (++i < m1->cols)
			result->array[ri][rj] += m1->array[ri][i] * m2->array[i][rj];
		rj++;
		ri += (rj == result->cols);
		rj *= (rj == result->cols);
	}
	return (result);
}

void	free_matrix(t_matrix_2d *m)
{
	int	i;

	if (!m || !m->array)
		return ;
	i = 0;
	while (i < m->rows)
	{
		if (m->array[i])
			free(m->array[i]);
		i++;
	}
	free(m->array);
	m->array = NULL;
}

int	create_matrix(t_matrix_2d *m, int rows, int cols)
{
	int	i;
	int	j;

	if (!m || rows <= 0 || cols <= 0)
		return (0);
	m->array = malloc((rows + 1) * sizeof(int *));
	if (!m->array)
		return (-1);
	i = 0;
	while (i < m->rows)
	{
		m->array[i] = malloc((cols) * sizeof(int));
		if (!m->array[i])
		{
			free_matrix(m);
			return (-1);
		}
		j = -1;
		while (++j < m->cols)
			m->array[i][j] = 0;
		i++;
	}
	m->array[i] = NULL;
	return (1);
}

int	copy_matrix(t_matrix_2d *dest, const t_matrix_2d *src)
{
	int	i;
	int	j;
	int	ret;

	if (!dest || !src || !src->array)
		return (1);
	ret = create_matrix(dest, src->rows, src->cols);
	if (ret < 1)
		return (ret);
	i = 0;
	while (i < src->rows)
	{
		j = -1;
		while (++j < src->cols)
			dest->array[i][j] = src->array[i][j];
		i++;
	}
	return (1);
}
