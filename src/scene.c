/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:21:30 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/19 15:24:02 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	create_shapes_arr(t_main *m, void **arr_pointer, int cnt, int shape)
{
	int	i;

	if (cnt == 0)
	{
		*arr_pointer = NULL;
		return ;
	}
	if (ft_malloc(arr_pointer, cnt, sizeof(t_object)))
		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
	i = -1;
	while (++i < cnt)
		(*((t_object **)arr_pointer))[i].object_type = shape;
}

static void	setup_shapes(t_main *m, int cnt[4])
{
	if (!m)
		return ;
	m->scene.co_cnt = 0;
	m->scene.pl_cnt = 0;
	m->scene.sp_cnt = 0;
	m->scene.cy_cnt = 0;
	create_shapes_arr(m, (void **)&m->scene.cones, cnt[CONE], CONE);
	create_shapes_arr(m, (void **)&m->scene.planes, cnt[PLANE], PLANE);
	create_shapes_arr(m, (void **)&m->scene.spheres, cnt[SPHERE], SPHERE);
	create_shapes_arr(m, (void **)&m->scene.cylinders, cnt[CYLINDER], CYLINDER);
}

void	init_scene(t_main *m, t_scene *s, double **objs)
{
	int	i;
	int	shape_cnt[4];

	if (!m || !s)
		return ;
	count_shapes(shape_cnt, objs);
	setup_shapes(m, shape_cnt);
	i = -1;
	while (objs[++i][0] != INVALID)
	{
		if (objs[i][0] == CONE)
			read_shape_values(m, &m->scene.cones[m->scene.co_cnt++], objs[i]);
		if (objs[i][0] == PLANE)
			read_shape_values(m, &m->scene.planes[m->scene.pl_cnt++], objs[i]);
		if (objs[i][0] == SPHERE)
			read_shape_values(m, &m->scene.spheres[m->scene.sp_cnt++], objs[i]);
		if (objs[i][0] == CYLINDER)
			read_shape_values(m, &m->scene.cylinders[m->scene.cy_cnt++], objs[i]);
		if (objs[i][0] == AMBIENT)
			read_light_values(&m->scene.ambient, objs[i]);
		if (objs[i][0] == LIGHT)
			read_light_values(&m->scene.light, objs[i]);
		if (objs[i][0] == CAMERA)
			read_camera_values(&m->scene.camera, objs[i]);
	}
}

void	setup_scene(t_main *m, t_scene *s)
{
	s->camera.focal_length = 1;
	m->vp_width = 2.0 * tan(s->camera.fov / 360) / s->camera.focal_length;
	m->vp_height = m->vp_width / m->aspect_ratio;
	s->camera.vp_u = m->vp_width / m->win_width;
	s->camera.vp_v = m->vp_height / m->win_height;
	assign(&s->camera.top_left_pos, s->camera.origin.x - (m->vp_width / 2) +
		(s->camera.vp_u / 2), s->camera.origin.y + (m->vp_height / 2) -
		(s->camera.vp_v / 2), s->camera.origin.z - s->camera.focal_length);
	// printf("~ %lf, %lf, %lf ~\n", m->vp_width, m->vp_height, m->vp_width * m->vp_height);
	// printf("~ %d, %d~\n", m->win_width, m->win_height);
}
