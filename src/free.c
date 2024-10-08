/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:48 by ehammoud          #+#    #+#             */
/*   Updated: 2024/10/08 04:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	ft_malloc(void **pointer, int n, int size)
{
	if (!pointer || n < 1 || size < 1)
		return (1);
	*pointer = malloc(n * size);
	if (!*pointer)
		return (-1);
	return (0);
}

void	free_double_array(double **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] && arr[i][0] != INVALID)
		free(arr[i++]);
	if (arr[i])
		free(arr[i]);
	free(arr);
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

void	free_scene(t_scene *s)
{
	free(s->planes);
	free(s->spheres);
	free(s->cylinders);
	free_matrix(&s->camera.trans_matrix);
}

void	free_and_exit(t_main *m, char *msg, int status)
{
	if (status && printf("Error\n") < 0)
		status = EXIT_FAILURE;
	if (printf("%s\n", msg) < 0)
		status = EXIT_FAILURE;
	free_double_array(m->objs);
	free_scene(&m->scene);
	if (m->img && m->mlx)
		mlx_destroy_image(m->mlx, m->img);
	if (m->mw && m->mlx)
		mlx_destroy_window(m->mlx, m->mw);
	if (m->mlx)
		free(m->mlx);
	exit(status);
}
