/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:44:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 00:44:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
			color_pixel(m, y, x, color);
		}
	}
}

void	background_gradient(t_main *m, t_ray *ray, int i, int j)
{
	double	a;
	int		c1;
	int		c2;
	t_color	bot_up;
	t_color	top_down;

	if (!m || !ray)
		return ;
	a = ray->orient.y / (2 * m->scene.camera.top_left_pos.y) + 0.5;
	assign(&bot_up, (1 - a) / 3, 0, (1 - a) / 3);
	c1 = (((int)(bot_up.x * 255)) << 16) +
		(((int)(bot_up.y * 255)) << 8) +
			(((int)(bot_up.z * 255)));
	assign(&top_down, 0, 0, 0);
	c2 = (((int)(top_down.x * 255)) << 16) +
		(((int)(top_down.y * 255)) << 8) +
			(((int)(top_down.z * 255)));
	color_pixel(m, i, j, c1 + c2);
}

void	draw_grid(t_main *m, t_ray *ray, int i, int j)
{
	if (!m || !ray)
		return ;
	if ((int)(ray->orient.x * 100) % 10 == 0)
		color_pixel(m, i, j, 0xcccccc);
	if ((int)(ray->orient.y * 100) % 10 == 0)
		color_pixel(m, i, j, 0xcccccc);
}
