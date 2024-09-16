/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:31:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/16 04:03:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
void	init_main_struct(t_main *m)
{
	m->mlx = NULL;
	m->mw = NULL;
	m->img = NULL;
	m->pixel = NULL;
	m->win_height = WIN_HEIGHT;
	m->win_width = m->win_height * ASPECT_RATIO;
	init_scene(&m->scene);
	// double arr[14][12] = 
	// {{CAMERA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//  {AMBIENT, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//  {LIGHT, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	//  {CONE, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	//  {CONE, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	//  {CONE, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	//  {CONE, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	//  {PLANE, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	//  {PLANE, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	//  {PLANE, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	//  {SPHERE, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	//  {SPHERE, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	//  {CYLINDER, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	//  {INVALID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	// };
	// double **ptr = malloc(sizeof(double *) * 14);
	// for (int i=0;i<14;i++)
	// 	ptr[i] = malloc(sizeof(double) * 12);
	// for (int i=0;i<14;i++)
	// 	for(int j=0;j<12;j++)
	// 		ptr[i][j] = arr[i][j];
	// setup_scene(m, ptr);
	// free_double_array(ptr);
	// free_scene(m->scene);
}

int	main( void )
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

	draw_rainbow(m); //our code

	mlx_expose_hook(m.mw, redraw, &m);
	mlx_hook(m.mw, 2, 1L << 0, keypress_hook, &m);
	mlx_hook(m.mw, 17, 1L << 2, exitbutton_hook, &m);
	mlx_put_image_to_window(m.mlx, m.mw, m.img, 0, 0);
	mlx_loop(m.mlx);
	return (0);
}
