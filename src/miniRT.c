/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:31:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/10/09 11:01:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "ft_math.h"

void	init_main_struct(t_main *m)
{
	m->busy = 0;
	m->mlx = NULL;
	m->mw = NULL;
	m->img = NULL;
	m->pixel = NULL;
	m->objs = NULL;
	m->win_height = WIN_HEIGHT;
	m->win_width = m->win_height * ASPECT_RATIO;
	m->aspect_ratio = ((double) m->win_width / m->win_height);
	init_scene(m, &m->scene, m->objs);
	setup_scene(m, &m->scene);
	free_double_array(m->objs);
	m->objs = NULL;
	if (m->scene.camera.fov < 0 || m->scene.camera.fov > 180)
		free_and_exit(m, "Error\nInvalid FOV value!\n", EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_main	m;

	if (ac != 2)
		free_and_exit(NULL, "Wrong number of arguments", 1);
	m.objs = open_file(av[1]);
	// init_main_struct(&m);
	// m.mlx = mlx_init();
	// if (!m.mlx)
	// 	free_and_exit(&m, FAILURE, EXIT_FAILURE);
	// m.mw = mlx_new_window(m.mlx, m.win_width, m.win_height, "miniFarty");
	// m.img = mlx_new_image(m.mlx, m.win_width, m.win_height);
	// if (!m.img)
	// 	free_and_exit(&m, FAILURE, EXIT_FAILURE);
	// m.pixel = mlx_get_data_addr(m.img, &m.pixel_bits, &m.line_bytes, &m.endian);
	// if (!m.mw || !m.pixel)
	// 	free_and_exit(&m, FAILURE, EXIT_FAILURE);
	// render_scene(&m);
	// mlx_expose_hook(m.mw, redraw, &m);
	// mlx_hook(m.mw, 2, 1L << 0, keypress_hook, &m);
	// mlx_hook(m.mw, 17, 1L << 2, exitbutton_hook, &m);
	// mlx_put_image_to_window(m.mlx, m.mw, m.img, 0, 0);
	// mlx_loop(m.mlx);
	free_and_exit(&m, "Done", 0);
	return (0);
}
