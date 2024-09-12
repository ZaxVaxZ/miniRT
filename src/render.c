/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:28:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/12 11:28:43 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	color_pixel(t_main m, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = (y * m.line_bytes) + (x * 4);
	if (m.pixel_bits != 32)
		color = mlx_get_color_value(m.mlx, color);
	if (m.endian == 1)
	{
		m.pixel[pixel_index + 0] = (color >> 24);
		m.pixel[pixel_index + 1] = (color >> 16) & 0xFF;
		m.pixel[pixel_index + 2] = (color >> 8) & 0xFF;
		m.pixel[pixel_index + 3] = (color) & 0xFF;
	}
	else if (m.endian == 0)
	{
		m.pixel[pixel_index + 0] = (color) & 0xFF;
		m.pixel[pixel_index + 1] = (color >> 8) & 0xFF;
		m.pixel[pixel_index + 2] = (color >> 16) & 0xFF;
		m.pixel[pixel_index + 3] = (color >> 24);
	}
}

void	draw_rainbow(t_main m)
{
	int	a, b, c, color;

	for(int y = 0; y < HEIGHT; ++y)
	{
		a = 0;
		b = 0;
		c = 255;
		for(int x = 0; x < WIDTH; ++x)
		{
			a += (!c && b > 0) - (!b && a > 0);
			b += (!a && c > 0) - (!c && b > 0);
			c += (!b && a > 0) - (!a && c > 0);
			color = (a << 16) + (b << 8) + c;
			color_pixel(m, x, y, color);
		}
	}
}
