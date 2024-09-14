/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:21:30 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/14 21:21:32 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	init_scene(t_scene *s)
{
	if (!s)
		return ;
	s->cones = NULL;
	s->planes = NULL;
	s->spheres = NULL;
	s->cylinders = NULL;
	s->camera.fov = 100;
	s->camera.origin.x = 0;
	s->camera.origin.y = 0;
	s->camera.origin.z = -1;
	s->camera.direct.x = 0;
	s->camera.direct.y = 0;
	s->camera.direct.z = 1;
}

static void	count_shapes(int count[4], double **objs)
{
	int	i;

	if (!objs || !objs[0])
		return ;
	i = -1;
	while (++i < 4)
		count[i] = 0;
	i = -1;
	while (objs[++i] != -1)
	{
		count[CONE] += (objs[i][0] == CONE);
		count[PLANE] += (objs[i][0] == PLANE);
		count[SPHERE] += (objs[i][0] == SPHERE);
		count[CYLINDER] += (objs[i][0] == CYLINDER);
	}
}

static void	setup_shapes(t_main *m, int cnt[4])
{
	if (!m)
		return ;
	if (cnt[CONE])
	{
		if (!ft_malloc((void **)&m->scene.cones, cnt[CONE] + 1, sizeof(t_object)))
			free_and_exit(m, "Memory allocation failed", 1);
	}
	if (cnt[PLANE])
	{
		if (!ft_malloc((void **)&m->scene.planes, cnt[PLANE] + 1, sizeof(t_object)))
			free_and_exit(m, "Memory allocation failed", 1);
	}
	if (cnt[SPHERE])
	{
		if (!ft_malloc((void **)&m->scene.spheres,
			cnt[SPHERE] + 1, sizeof(t_object)))
			free_and_exit(m, "Memory allocation failed", 1);
	}
	if (cnt[CYLINDER])
	{
		if (!ft_malloc((void **)&m->scene.cylinders,
			cnt[CYLINDER] + 1, sizeof(t_object)))
			free_and_exit(m, "Memory allocation failed", 1);
	}
}

void	setup_scene(t_main *m, double **objs)
{
	int	i;
	int	shape_cnt[4];

	count_shapes(shape_cnt, objs);
	
}
