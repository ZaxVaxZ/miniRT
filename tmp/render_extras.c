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
#define GRAY	 80,  80,  80
#define RED		255,   0,   0
#define DARKRED	 80,   0,   0
#define GREEN	  0, 205,   0
#define DARKGREEN 0,  80,   0
#define BLUE	  0,   0, 255
#define DARKBLUE  0,   0,  80
#define CYAN	  0, 255, 255
#define OILY	 60, 255,  90
#define PINK	255,  32, 255
#define YELLOW	255, 255,   0
#define MAGENTA	255,   0, 255
#define DARKY	 80,  80,   0
#define ORANGE	255, 100,   0
#define BROWN	 80,  40,   0
#define PURPLE	180,   0, 180

double	**get_objs(void)
{
	int		rows;
	double	**ret;

	double sr=2;
	double pl=4;
	rows = 16;
	double arr[16][12] = 
	// {{CAMERA, -3,-3, -3, 4, 4, 4, 100, 0,   0,   0,   0},
	{{CAMERA, -3,-3, -1, 4, 4, 1, 100, 0,   0,   0,   0},
	// {{CAMERA, 0,0, -3, 0, 0, 1, 100, 0,   0,   0,   0},

	 {AMBIENT, 0, 0, 0, 0, 0, 0, 0.3, 0, 255, 255, 255},

	 {PLANE, -pl, 0, 0, 1, 0, 0, 0.5, 0, DARKGREEN},
	 {PLANE, 0, 0, -pl, 0, 0, 2, 0.5, 0, DARKRED},
	 {PLANE, 0, -pl, 0, 0, 1, 0, 0.5, 0, DARKBLUE},
	 {PLANE,  pl, 0, 0, 1, 0, 0, 0.5, 0, BROWN},
	 {PLANE, 0, 0,  pl, 0, 0, 2, 0.5, 0, GRAY},
	 {PLANE, 0,  pl, 0, 0, 1, 0, 0.5, 0, DARKY},

	 {SPHERE,   0,  sr,   0, 0, 1, 0, 0.9, 1, BLUE},
	 {SPHERE,   0, -sr,   0, 0, 1, 0, 0.9, 1, MAGENTA},
	 {SPHERE,  sr,   0,   0, 0, 1, 0, 0.9, 1, YELLOW},
	 {SPHERE, -sr,   0,   0, 0, 1, 0, 0.9, 1, RED},
	 {SPHERE,   0,   0,  sr, 0, 0, 0, 0.9, 0, GREEN},
	 {SPHERE,   0,   0, -sr, 0, 0, 0, 0.9, 0, PURPLE},
	 { LIGHT,   0,   0,   0, 0, 1, 0, 1.5, 8, WHITE},
	 
	 {INVALID, 0, 0, 0, 0, 0, 0,   0, 0,   0,   0,   0}
	};


	
	// double sr=1;
	// double pl=4;
	// rows = 18;
	// double arr[18][12] = 
	// // {{CAMERA, -3,-3, -3, 4, 4, 4, 100, 0,   0,   0,   0},
	// {{CAMERA, -3,-3, -1, 4, 4, 1, 100, 0,   0,   0,   0},
	// // {{CAMERA, 0,0, -3, 0, 0, 1, 100, 0,   0,   0,   0},

	//  {AMBIENT, 0, 0, 0, 0, 0, 0, 0.2, 0, 255, 255, 255},

	//  {PLANE, -pl, 0, 0, 1, 0, 0, 0.5, 0, DARKGREEN},
	//  {PLANE, 0, 0, -pl, 0, 0, 2, 0.5, 0, DARKRED},
	//  {PLANE, 0, -pl, 0, 0, 1, 0, 0.5, 0, DARKBLUE},
	//  {PLANE,  pl, 0, 0, 1, 0, 0, 0.5, 0, BROWN},
	//  {PLANE, 0, 0,  pl, 0, 0, 2, 0.5, 0, GRAY},
	//  {PLANE, 0,  pl, 0, 0, 1, 0, 0.5, 0, PURPLE},

	//  {SPHERE,  sr,  sr,  sr, 0, 1, 0, 0.9, 1, BLUE},
	//  {SPHERE, -sr,  sr, -sr, 0, 1, 0, 0.9, 1, GREEN},
	//  {SPHERE, -sr,  sr,  sr, 0, 1, 0, 0.9, 1, YELLOW},
	//  {SPHERE,  sr,  sr, -sr, 0, 1, 0, 0.9, 1, RED},
	// //  {SPHERE,   0,   0,   0, 0, 1, 0, 0.9, 1, WHITE},
	//  { LIGHT,   0,   0,   0, 0, 1, 0, 1.5, 8, WHITE},
	//  {SPHERE,  sr, -sr,  sr, 0, 0, 0, 0.9, 0, MAGENTA},
	//  {SPHERE, -sr, -sr, -sr, 0, 0, 0, 0.9, 0, PURPLE},
	//  {SPHERE, -sr, -sr,  sr, 0, 0, 0, 0.9, 0, OILY},
	//  {SPHERE,  sr, -sr, -sr, 0, 0, 0, 0.9, 0, CYAN},
	 
	//  {INVALID, 0, 0, 0, 0, 0, 0,   0, 0,   0,   0,   0}
	// };



	// rows = 11;
	// double arr[11][12] = 
	// // {{CAMERA, -3,-3, -3, 4, 4, 4, 100, 0,   0,   0,   0},
	// // {{CAMERA, -3,-3, -1, 4, 4, 1, 100, 0,   0,   0,   0},
	// {{CAMERA, 0,0, -3, 0, 0, 1, 100, 0,   0,   0,   0},

	//  {AMBIENT, 0, 0, 0, 0, 0, 0, 0.2, 0, 255, 255, 255},

	//  {PLANE, -pl, 0, 0, 1, 0, 0, 0.5, 0, DARKGREEN},
	//  {PLANE, 0, 0, -pl, 0, 0, 2, 0.5, 0, DARKRED},
	//  {PLANE, 0, -pl, 0, 0, 1, 0, 0.5, 0, DARKBLUE},
	//  {PLANE, pl, 0, 0, 1, 0, 0, 0.5, 0, BROWN},
	//  {PLANE, 0, 0, pl, 0, 0, 2, 0.5, 0, GRAY},
	//  {PLANE, 0, pl, 0, 0, 1, 0, 0.5, 0, DARKY},

	// //  {CYLINDER, sr, sr, sr, 0, 1, 0, 0.9, 1, RED},
	// //  {CYLINDER, -sr, sr, -sr, 0, 1, 0, 0.9, 1, GREEN},
	//  {CYLINDER, -sr, sr, sr, 0, 1, 0, 0.9, 1, YELLOW},
	// //  {CYLINDER, sr, sr, -sr, 0, 1, 0, 0.9, 1, BLUE},
	//  {LIGHT, 0, 0, 0, 0, 1, 0, 1, 8, WHITE},
	// //  {SPHERE, sr, -sr, sr, 0, 0, 0, 0.9, 0, PINK},
	// //  {SPHERE, -sr, -sr, -sr, 0, 0, 0, 0.9, 0, PURPLE},
	// //  {SPHERE, -sr, -sr, sr, 0, 0, 0, 0.9, 0, OILY},
	// //  {SPHERE, sr, -sr, -sr, 0, 0, 0, 0.9, 0, CYAN},
	 
	//  {INVALID, 0, 0, 0, 0, 0, 0,   0, 0,   0,   0,   0}
	// };
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
