/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:28:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/18 21:01:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	color_pixel(t_main *m, int x, int y, int color)
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

void	draw_rainbow(t_main *m)
{
	int	a, b, c, color;

	if (!m || !m->pixel)
		return ;
	for(int y = 0; y < m->win_height; ++y)
	{
		a = 0;
		b = 0;
		c = 255;
		for(int x = 0; x < m->win_width; ++x)
		{
			a += (!c && b > 0) - (!b && a > 0);
			b += (!a && c > 0) - (!c && b > 0);
			c += (!b && a > 0) - (!a && c > 0);
			color = (a << 16) + (b << 8) + c;
			color_pixel(m, x, y, color);
		}
	}
}

void	render_scene(t_main *m)
{
	int	i;
	int	j;
    t_point	top_left;
	t_ray	ray;
	double	ret;

	if (m->busy)
		return ;
	m->busy = 1;
	scalar_op(&top_left, &m->scene.camera.top_left_pos, '+', 0);
	// top_left.x += 0.5 * m->scene.camera.vp_u_diff.x;
	// top_left.y += 0.5 * m->scene.camera.vp_v_diff.y;
	i = -1;
	scalar_op(&ray.origin, &m->scene.camera.origin, '+', 0);
    while (++i < m->win_height)
	{
		j = -1;
		while (++j < m->win_width)
		{
			scalar_op(&ray.orient, &top_left, '+', 0);
			ray.orient.x += j;
			ray.orient.x /= m->win_height;
			ray.orient.x *= 2;
			ray.orient.x -= 1;
			// ray.orient.x *= m->scene.camera.fov;
			ray.orient.y += i;
			ray.orient.y /= m->win_height;
			ray.orient.y *= 2;
			ray.orient.y -= 1;
			// ray.orient.y *= m->scene.camera.fov;
			// assign(&ray.orient,
			// 	((double)j / m->win_width * 2 - 1) * m->aspect_ratio,
			// 	((double)i / m->win_height * 2 - 1),
			// 	m->scene.camera.origin.z);
			// scalar_op(&ray.orient, &top_left, '+', 0);
			// ray.orient.x += (j * m->scene.camera.vp_u.x);
			// ray.orient.y += (i * m->scene.camera.vp_v.y);
			// vector_op(&ray.orient, &ray.orient, '-', &ray.origin);
			scalar_op(&ray.orient, &ray.orient, '/', sqrt(dot(ray.orient, ray.orient)));
			if (!intersect_sphere(&ray, &m->scene.spheres[0], &ret))
				color_pixel(m, j, i, ret * 0xffff00);
			// double a=0.5 * (ray.orient.y + 1.0);
			// color_pixel(m, j, i, (int)((1 - a) * 0xffffff + a * 0xff));
			// color_pixel(m, j, i, (int)((1 - a) * 0xffffff + a * 0x88ccff));
			// color_pixel(m, j, i, (int)(ray.orient.y * 0xffffff));
			// if (ray.orient.x > 0.5)
			// 	color_pixel(m, j, i, 0);
			// else
			// if (ray.orient.x <= 0 && ray.orient.y >= -0)
			// 	color_pixel(m, j, i, 0xff0000);
			// else if (ray.orient.x <= 0)
			// 	color_pixel(m, j, i, 0xff00);
			// else if (ray.orient.y >= -0)
			// 	color_pixel(m, j, i, 0xff);
			// else
			// 	color_pixel(m, j, i, 0xffff00);
		}
	}
	m->busy = 0;
}
