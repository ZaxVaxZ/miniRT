/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:31:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/14 18:19:22 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_main_struct(t_main *m)
{
	m->mlx = NULL;
	m->mw = NULL;
	m->img = NULL;
	m->pixel = NULL;
	m->win_height = WIN_HEIGHT;
	m->win_width = m->win_height * ASPECT_RATIO;
	init_scene(&m->scene);
}

int	main( void )
{
	t_main	m;

	init_main_struct(&m);
	m.mlx = mlx_init();
	if (!m.mlx)
		free_and_exit(&m, "Unexpected error", EXIT_FAILURE);
	m.mw = mlx_new_window(m.mlx, m.win_width, m.win_height, "miniFarty");
	m.img = mlx_new_image(m.mlx, m.win_width, m.win_height);
	if (!m.img)
		free_and_exit(&m, "Unexpected error", EXIT_FAILURE);
	m.pixel = mlx_get_data_addr(m.img, &m.pixel_bits, &m.line_bytes, &m.endian);
	if (!m.mw || !m.pixel)
		free_and_exit(&m, "Unexpected error", EXIT_FAILURE);

	draw_rainbow(m); //our code
	

	mlx_expose_hook(m.mw, redraw, &m);
	mlx_hook(m.mw, 2, 1L << 0, keypress_hook, &m);
	mlx_hook(m.mw, 17, 1L << 2, exitbutton_hook, &m);
	mlx_put_image_to_window(m.mlx, m.mw, m.img, 0, 0);
	mlx_loop(m.mlx);
	return (0);
}
