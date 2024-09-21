/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:28:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/22 03:10:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	color_pixel(t_main *m, int x, int y, unsigned int color)
{
	int	pixel_index;

	if (!m || !m->pixel)
		return ;
	pixel_index = (y * m->line_bytes) + (x * 4);
	if (m->pixel_bits != 32)
		color = mlx_get_color_value(m->mlx, color);
	if (m->endian == 1)
	{
		m->pixel[pixel_index + 0] = (color >> 24);
		m->pixel[pixel_index + 1] = (color >> 16) & 0xFF;
		m->pixel[pixel_index + 2] = (color >> 8) & 0xFF;
		m->pixel[pixel_index + 3] = (color) & 0xFF;
	}
	else if (m->endian == 0)
	{
		m->pixel[pixel_index + 0] = (color) & 0xFF;
		m->pixel[pixel_index + 1] = (color >> 8) & 0xFF;
		m->pixel[pixel_index + 2] = (color >> 16) & 0xFF;
		m->pixel[pixel_index + 3] = (color >> 24);
	}
}

static unsigned int	color_to_hex(t_color color)
{
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	if (color.x < 0)
		color.x = 0;
	if (color.y < 0)
		color.y = 0;
	if (color.z < 0)
		color.z = 0;
	return ((((unsigned int)(color.x * 255)) << 16) +
		(((unsigned int)(color.y * 255)) << 8) +
			(((unsigned int)(color.z * 255))));
}

void	hit_objects(t_main *m, t_ray *ray, int i, int j)
{
	int		u;
	t_hit	hit;

	hit.i = i;
	hit.j = j;
	hit.closest = -1;
	assign(&hit.color, 0, 0, 0);
	scalar_op(&hit.ray, ray, '+', 0);
	u = -1;
	while (++u < m->scene.co_cnt)
		hit_sphere(ray, hit);
	u = -1;
	while (++u < m->scene.pl_cnt)
		hit_sphere(ray, hit);
	u = -1;
	while (++u < m->scene.sp_cnt)
		hit_sphere(ray, hit);
	u = -1;
	while (++u < m->scene.cy_cnt)
		hit_sphere(ray, hit);
}

void	render_scene(t_main *m)
{
	double	ret;
	t_ray	ray;
	int		i;
	int		j;

	if (m->busy)
		return ;
	m->busy = 1;
	scalar_op(&ray.origin, &m->scene.camera.origin, '+', 0);
	i = -1;
	while (++i < m->win_height)
	{
		j = -1;
		while (++j < m->win_width)
		{
			scalar_op(&ray.orient, &m->scene.camera.top_left_pos, '+', 0);
			ray.orient.x += j * m->scene.camera.vp_u;
			ray.orient.y += i * m->scene.camera.vp_v;
			hit_objects(m, &ray, i, j);
		}
	}
	m->busy = 0;
}
