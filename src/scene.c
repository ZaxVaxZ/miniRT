/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:21:30 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/15 16:24:19 by marvin           ###   ########.fr       */
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

static void	create_shapes_arr(void **arr_pointer, int cnt, int shape)
{
	int	i;

	if (cnt <= 0)
		return ;
	if (!ft_malloc(arr_pointer, cnt + 1, sizeof(t_object)))
		free_and_exit(m, "Memory allocation failed", EXIT_FAILURE);
	i = -1;
	while (++i < cnt)
		arr_pointer[i].object_type = shape;
}

static void	setup_shapes(t_main *m, int cnt[4])
{
	int	i;

	if (!m)
		return ;
	m->scene.co_cnt = 0;
	m->scene.pl_cnt = 0;
	m->scene.sp_cnt = 0;
	m->scene.cy_cnt = 0;
	create_shapes_arr((void **)&m->scene.cones, cnt[CONE], CONE);
	create_shapes_arr((void **)&m->scene.planes, cnt[PLANE], PLANE);
	create_shapes_arr((void **)&m->scene.spheres, cnt[SPHERE], SPHERE);
	create_shapes_arr((void **)&m->scene.cylinders, cnt[CYLINDER], CYLINDER);
}

void	setup_scene(t_main *m, double **objs)
{
	int	i;

	count_shapes(shape_cnt, objs);
	setup_shapes(m, shape_cnt);
	i = -1;
	while (objs[++i][0] != INVALID)
	{
		if (objs[0] == CONE)
			read_shape_values(m, &m->scene.cones[m->scene.co_cnt++], objs[i]);
		if (objs[0] == PLANE)
			read_shape_values(m, &m->scene.planes[m->scene.pl_cnt++], objs[i]);
		if (objs[0] == SPHERE)
			read_shape_values(m, &m->scene.spheres[m->scene.sp_cnt++], objs[i]);
		if (objs[0] == CYLINDER)
			read_shape_values(m, &m->scene.cylinders[m->scene.cy_cnt++], objs[i]);
		if (objs[0] == AMBIENT)
			read_light_values(m, &m->scene.ambient, objs[i]);
		if (objs[0] == LIGHT)
			read_light_values(m, &m->scene.light, objs[i]);
		if (objs[0] == CAMERA)
			read_camera_values(m, &m->scene.camera, objs[i]);
	}
}
