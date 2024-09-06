#include "main.h"
#include "ft_printf.h"

void	init_main_struct(t_main *m)
{
	m->mlx = NULL;
	m->mw = NULL;
	m->img = NULL;
	m->pixel = NULL;
}

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
			if (!a && c > 0)
			{
				b++;
				c--;
			}
			if (b > 0 && !c)
			{
				b--;
				a++;
			}
			if (!b && a > 0)
			{
				a--;
				c++;
			}
			color = (a << 16) + (b << 8) + c;
			color_pixel(m, x, y, color);
		}
	}
}

void	free_and_exit(t_main *m, int msg, int status)
{
	int	ret;

	ret = 0;
	if (msg == SUCCESS)
		ret = ft_printf("Execution Complete!\n");
	if (msg == FAILURE)
		ret = write(2, "Error\nUnexpected Error!\n", 24);
	if (msg == ERR_MEM)
		ret = write(2, "Error\nMemory allocation failure!\n", 33);
	if (ret < 0)
		status = FAILURE;
	if (m->img && m->mlx)
		mlx_destroy_image(m->mlx, m->img);
	if (m->mw && m->mlx)
		mlx_destroy_window(m->mlx, m->mw);
	if (m->mlx)
		free(m->mlx);
	exit(status);
}

int	keypress_hook(int keypress, t_main *m)
{
	if (keypress == ESC)
	{
		free_and_exit(m, 0, 0);
	}
	return (0);
}

int	exitbutton_hook(t_main *m)
{
	free_and_exit(m, 0, 0);
	return (0);
}

int	main( void )
{
	t_main	m;

	init_main_struct(&m);
	m.mlx = mlx_init();
	if (!m.mlx)
		free_and_exit(&m, FAILURE, 1);
	m.mw = mlx_new_window(m.mlx, WIDTH, HEIGHT, "miniFarty");
	m.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);
	if (!m.img)
		free_and_exit(&m, FAILURE, 1);
	m.pixel = mlx_get_data_addr(m.img, &m.pixel_bits, &m.line_bytes, &m.endian);
	if (!m.mw || !m.pixel)
		free_and_exit(&m, FAILURE, 1);

	draw_rainbow(m); //our code

	mlx_put_image_to_window(m.mlx, m.mw, m.img, 0, 0);
	mlx_hook(m.mw, 2, 1L << 0, &keypress_hook, &m);
	mlx_hook(m.mw, 17, 1L << 2, exitbutton_hook, &m);
	mlx_loop(m.mlx);
	return (0);
}

// int	main( void )
// {
// 	t_main	m;

// 	m.mlx = mlx_init();
// 	m.mw = mlx_new_window(m.mlx, WIDTH, HEIGHT, "miniFarty");
// 	m.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);
// 	m.pixel = mlx_get_data_addr(m.img, &m.pixel_bits, &m.line_bytes, &m.endian);
// 	ft_printf("Hello!\n");
// 	int a,b,c;
// 	for(int y = 0; y < HEIGHT; ++y)
// 	{
// 		a = 0;
// 		b = 0;
// 		c = 255;
// 		for(int x = 0; x < WIDTH; ++x)
// 		{
// 			if (!a && c > 0)
// 			{
// 				b++;
// 				c--;
// 			}
// 			if (b > 0 && !c)
// 			{
// 				b--;
// 				a++;
// 			}
// 			if (!b && a > 0)
// 			{
// 				a--;
// 				c++;
// 			}
// 			int color;
// 			color = (a << 16) + (b << 8) + c;
// 			color_pixel(m, x, y, color);
// 		}
// 	}
// 	if (m.img)
// 		mlx_put_image_to_window(m.mlx, m.mw, m.img, 0, 0);
// 	mlx_hook(m.mw, 2, 1L << 0, &keypress_hook, &m);
// 	mlx_hook(m.mw, 17, 1L << 2, exitbutton_hook, &m);
// 	mlx_loop(m.mlx);
// 	return (0);
// }
