/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:31:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/19 16:30:02 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_main_struct(t_main *m)
{
	m->busy = 0;
	m->mlx = NULL;
	m->mw = NULL;
	m->img = NULL;
	m->pixel = NULL;
	m->win_height = WIN_HEIGHT;
	m->win_width = m->win_height * ASPECT_RATIO;
	m->aspect_ratio = ((double) m->win_width / m->win_height);
	int rows=5;
	double arr[5][12] = 
	{{CAMERA, 0, 0, -1, 0, 0, 1, 100, 0, 0, 0, 0},
	 {AMBIENT, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {LIGHT, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	//  {CONE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//  {CONE, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	//  {CONE, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	//  {CONE, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	//  {PLANE, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	//  {PLANE, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	//  {PLANE, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	 {SPHERE, 0, 0, 2, 0, 0, 0, 0.05, 0, 255, 0, 255},
	//  {SPHERE, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	//  {CYLINDER, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	 {INVALID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	double **ptr = malloc(sizeof(double *) * rows);
	for (int i=0;i<rows;i++)
		ptr[i] = malloc(sizeof(double) * 12);
	for (int i=0;i<rows;i++)
		for(int j=0;j<12;j++)
			ptr[i][j] = arr[i][j];
	init_scene(m, &m->scene, ptr);
	setup_scene(m, &m->scene);
	free_double_array(ptr);
}

int	main(void)
{
	t_main	m;

	init_main_struct(&m);
	m.mlx = mlx_init();
	if (!m.mlx)
		free_and_exit(&m, FAILURE, EXIT_FAILURE);
	m.mw = mlx_new_window(m.mlx, m.win_width, m.win_height, "miniFarty");
	m.img = mlx_new_image(m.mlx, m.win_width, m.win_height);
	if (!m.img)
		free_and_exit(&m, FAILURE, EXIT_FAILURE);
	m.pixel = mlx_get_data_addr(m.img, &m.pixel_bits, &m.line_bytes, &m.endian);
	if (!m.mw || !m.pixel)
		free_and_exit(&m, FAILURE, EXIT_FAILURE);

	// draw_rainbow(&m); //our code
	render_scene(&m);

	mlx_expose_hook(m.mw, redraw, &m);
	mlx_hook(m.mw, 2, 1L << 0, keypress_hook, &m);
	mlx_hook(m.mw, 17, 1L << 2, exitbutton_hook, &m);
	mlx_put_image_to_window(m.mlx, m.mw, m.img, 0, 0);
	mlx_loop(m.mlx);
	return (0);
}

// void	print_camera(t_camera *o)
// {
// 	printf("LIGHT: (%lf, %lf, %lf) %lf [%lf - %lf - %lf]\n", o->origin.x, o->origin.y, o->origin.z, o->fov, o->orient.x, o->orient.y, o->orient.z);
// }

// void	print_light(t_light *o)
// {
// 	if (o->is_ambient)
// 		printf("AMBIENT: %lf [%lf - %lf - %lf]\n", o->brightness, o->color.x, o->color.y, o->color.z);
// 	else
// 		printf("LIGHT: (%lf, %lf, %lf) %lf [%lf - %lf - %lf]\n", o->origin.x, o->origin.y, o->origin.z, o->brightness, o->color.x, o->color.y, o->color.z);
// }

// void	print_object(t_object *o)
// {
// 	if (o->object_type == CONE)
// 		printf("CONE: (%lf, %lf, %lf) {%lf, %lf, %lf} %lf %lf [%lf - %lf - %lf]\n", o->origin.x, o->origin.y, o->origin.z, o->orient.x, o->orient.y, o->orient.z, o->height, o->radius, o->color.x, o->color.y, o->color.z);
// 	if (o->object_type == PLANE)
// 		printf("PLANE: (%lf, %lf, %lf) {%lf, %lf, %lf} [%lf - %lf - %lf]\n", o->origin.x, o->origin.y, o->origin.z, o->orient.x, o->orient.y, o->orient.z, o->color.x, o->color.y, o->color.z);
// 	if (o->object_type == SPHERE)
// 		printf("SPHERE: (%lf, %lf, %lf) %lf [%lf - %lf - %lf]\n", o->origin.x, o->origin.y, o->origin.z, o->radius, o->color.x, o->color.y, o->color.z);
// 	if (o->object_type == CYLINDER)
// 		printf("CYLINDER: (%lf, %lf, %lf) {%lf, %lf, %lf} %lf %lf [%lf - %lf - %lf]\n", o->origin.x, o->origin.y, o->origin.z, o->orient.x, o->orient.y, o->orient.z, o->height, o->radius, o->color.x, o->color.y, o->color.z);
// }