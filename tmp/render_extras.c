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

#define BLACK	0,	   0,   0
#define WHITE	255, 255, 255
#define GRAY	120, 120, 120
#define RED		255,   0,   0
#define DARKRED	120,   0,   0
#define GREEN	  0, 255,   0
#define DARKGREEN 0, 120,   0
#define BLUE	  0,   0, 255
#define DARKBLUE  0,   0, 120
#define CYAN	  0, 255, 255
#define PINK	255,   32, 255
#define YELLOW	255, 255,   0
#define DARKY	120, 120,   0
#define ORANGE	255, 100,   0
#define BROWN	120,  40,   0
#define PURPLE	180,   0, 180

double	**get_objs(void)
{
	int		rows;
	double	**ret;

	rows = 19;
	double arr[19][12] = 
	{{CAMERA, -3,-3, -1, 4, 4, 1, 100, 0,   0,   0,   0},
	 {AMBIENT, 0, 0, 0, 0, 0, 0, 0, 0.2, 255, 255, 255},
	 {LIGHT,   0, 0, 0, 0, 0, 0, 0.8, 0, 255, 255, 255},

	 {PLANE, -4, 0, 0, 1, 0, 0, 0.5, 0, DARKGREEN},
	 {PLANE, 0, 0, -4, 0, 0, 2, 0.5, 0, DARKRED},
	 {PLANE, 0, -4, 0, 0, 1, 0, 0.5, 0, DARKBLUE},
	 {PLANE, 4, 0, 0, -1, 0, 0, 0.5, 0, BROWN},
	 {PLANE, 0, 0, 4, 0, 0, -2, 0.5, 0, GRAY},
	 {PLANE, 0, 4, 0, 0, -1, 0, 0.5, 0, DARKY},

	 {SPHERE, 1, 1, 1, 0, 0, 0, 0.5, 0, RED},
	 {SPHERE, -1, 1, -1, 0, 0, 0, 0.5, 0, GREEN},
	 {SPHERE, -1, 1, 1, 0, 0, 0, 0.5, 0, YELLOW},
	 {SPHERE, 1, 1, -1, 0, 0, 0, 0.5, 0, BLUE},
	 {CYLINDER, 0, 0, 0, 0, 1, 0, 0.5, 3, WHITE},
	 {SPHERE, 1, -1, 1, 0, 0, 0, 0.5, 0, PINK},
	 {SPHERE, -1, -1, -1, 0, 0, 0, 0.5, 0, ORANGE},
	 {SPHERE, -1, -1, 1, 0, 0, 0, 0.5, 0, PURPLE},
	 {SPHERE, 1, -1, -1, 0, 0, 0, 0.5, 0, CYAN},
	 
	 {INVALID, 0, 0, 0, 0, 0, 0,   0, 0,   0,   0,   0}
	};
	ret = malloc(sizeof(double *) * rows);
	for (int i=0;i<rows;i++)
		ret[i] = malloc(sizeof(double) * 12);
	for (int i=0;i<rows;i++)
		for(int j=0;j<12;j++)
			ret[i][j] = arr[i][j];
	return (ret);
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
