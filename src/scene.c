/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:21:30 by ehammoud          #+#    #+#             */
/*   Updated: 2024/10/09 15:11:15 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	setup_shapes(t_main *m, int cnt[4])
{
	if (!m)
		return ;
	m->scene.pl_cnt = 0;
	m->scene.sp_cnt = 0;
	m->scene.cy_cnt = 0;
	create_shapes_arr(m, (void **)&m->scene.planes, cnt[PLANE], PLANE);
	create_shapes_arr(m, (void **)&m->scene.spheres, cnt[SPHERE], SPHERE);
	create_shapes_arr(m, (void **)&m->scene.cylinders, cnt[CYLINDER], CYLINDER);
}

void	init_scene(t_main *m, t_scene *s, double **objs)
{
	int	i;
	int	shape_cnt[3];

	count_shapes(shape_cnt, objs);
	setup_shapes(m, shape_cnt);
	i = -1;
	while (objs[++i])
	{
		if (is_equal(objs[i][0], PLANE))
			read_shape_values(m, &s->planes[s->pl_cnt++], objs[i]);
		if (is_equal(objs[i][0], SPHERE))
			read_shape_values(m, &s->spheres[s->sp_cnt++], objs[i]);
		if (is_equal(objs[i][0], CYLINDER))
			read_shape_values(m, &s->cylinders[s->cy_cnt++], objs[i]);
		if (is_equal(objs[i][0], CAMERA))
			read_camera_values(m, &s->camera, objs[i]);
		if (is_equal(objs[i][0], AMBIENT))
			read_light_values(m, &s->ambient, objs[i]);
		if (is_equal(objs[i][0], LIGHT))
			read_light_values(m, &s->light, objs[i]);
	}
}

void	setup_scene(t_main *m, t_scene *s)
{
	s->camera.focal_len = 1;
	m->vp_width = 2.0 * tan((s->camera.fov * PI) / 360) / s->camera.focal_len;
	m->vp_height = m->vp_width / m->aspect_ratio;
	s->camera.vp_u = m->vp_width / m->win_width;
	s->camera.vp_v = m->vp_height / m->win_height;
	assign(&s->camera.top_left_pos,
		-(m->vp_width / 2.0) + (s->camera.vp_u / 2.0),
		(m->vp_height / 2.0) - (s->camera.vp_v / 2.0),
		-s->camera.focal_len);
}

static int	shadows(t_main *m, t_hit *h, t_ray ray, t_object *obj)
{
	t_vector	diff1;
	t_vector	diff2;
	t_hit		hit;

	if (obj == h->obj)
		return (0);
	hit.closest = -1;
	vector_op(&diff1, &m->scene.light.origin, '-', &ray.origin);
	vector_op(&diff2, &m->scene.light.origin, '-', &obj->origin);
	if (dot(diff1, diff2) < 0)
		return (0);
	if (obj->object_type == SPHERE)
		return (hit_sphere(ray, obj, &hit));
	else if (obj->object_type == PLANE)
		return (hit_plane(ray, obj, &hit));
	else
		return (hit_cylinder(ray, obj, &hit));
}

int	interrupted(t_main *m, t_hit *h)
{
	int		u;
	t_ray	ray;

	copy_vector(&ray.origin, &h->hitp);
	vector_op(&ray.orient, &m->scene.light.origin, '-', &h->hitp);
	normalize(&ray.orient);
	u = 0;
	while (u < m->scene.sp_cnt || u < m->scene.pl_cnt
		|| u < m->scene.cy_cnt)
	{
		if (u < m->scene.sp_cnt && shadows(m, h, ray, &m->scene.spheres[u]))
			return (1);
		if (u < m->scene.pl_cnt && shadows(m, h, ray, &m->scene.planes[u]))
			return (1);
		if (u < m->scene.cy_cnt && shadows(m, h, ray, &m->scene.cylinders[u]))
			return (1);
		u++;
	}
	return (0);
}
