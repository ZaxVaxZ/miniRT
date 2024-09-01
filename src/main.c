#include "main.h"

#define HEIGHT 512
#define WIDTH  1024



void	color_pixel()
{
	if (pixel_bits != 32)
		color = mlx_get_color_value(m.m, color);
	int pixel = (y * line_bytes) + (x * 4);

	if (endian == 1)        // Most significant (Alpha) byte first
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (endian == 0)   // Least significant (Blue) byte first
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}

int exitbutton(void *data)
{
	t_main *m = (t_main*)data;
	if (m->img && m->m)
		mlx_destroy_image(m->m, m->img);
	if (m->mw)
		mlx_destroy_window(m->m, m->mw);
	if (m->m)
		free(m->m);
	printf("BYE!\n");
	exit(0);
}

int	main( void )
{
	t_main m;
	printf("HELLO!\n");
	m.m = mlx_init();
	m.mw = mlx_new_window(m.m, 1024, 512, "miniFarty");
	printf("AND...\n");
	int x,y;
	m.img = mlx_new_image(m.m, WIDTH, HEIGHT);
	int pixel_bits;
	int line_bytes;
	int endian;
	int a,b,c;
	char *buffer = mlx_get_data_addr(m.img, &pixel_bits, &line_bytes, &endian);
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
			int color;
			color = (a << 16) + (b << 8) + c;
			if (pixel_bits != 32)
				color = mlx_get_color_value(m.m, color);
			int pixel = (y * line_bytes) + (x * 4);

			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
		}
	}
	if (m.img)
		mlx_put_image_to_window(m.m, m.mw, m.img, 0, 0);
	else
		printf("WAAAA\n");
	// mlx_hook(data.win, 2, 1L << 0, &on_keypress, &data);
	mlx_hook(m.mw, 17, 1L << 2, exitbutton, &m);
	mlx_loop(m.m);
	return (0);
}

//////////
// #include "main.h"
// #include "mlx.h"
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct mh {
// 	void *m;
// 	void *mw;
// 	void *img;
// } t_main;

// int exitbutton(void *data)
// {
// 	t_main *m = (t_main*)data;
// 	if (m->img && m->m)
// 		mlx_destroy_image(m->m, m->img);
// 	if (m->mw)
// 		mlx_destroy_window(m->m, m->mw);
// 	if (m->m)
// 		free(m->m);
// 	printf("BYE!\n");
// 	exit(0);
// }
// #define HEIGHT 255
// #define WIDTH  256
// int	main( void )
// {
// 	t_main m;
// 	printf("HELLO!\n");
// 	m.m = mlx_init();
// 	m.mw = mlx_new_window(m.m, 982, 512, "miniFarty");
// 	printf("AND...\n");
// 	int x,y;
// 	m.img = mlx_new_image(m.m, WIDTH, HEIGHT);
// 	int pixel_bits;
// 	int line_bytes;
// 	int endian;
// 	char *buffer = mlx_get_data_addr(m.img, &pixel_bits, &line_bytes, &endian);
// 	for(int y = 0; y < HEIGHT; ++y)
// 	{
// 	for(int x = 0; x < WIDTH; ++x)
// 	{
// 		int color = y<<x/16;//0xABCDEF;
// 	if (pixel_bits != 32)
// 		color = mlx_get_color_value(m.m, color);
// 		int pixel = (y * line_bytes) + (x * 4);

// 		if (endian == 1)        // Most significant (Alpha) byte first
// 		{
// 			buffer[pixel + 0] = (color >> 24);
// 			buffer[pixel + 1] = (color >> 16) & 0xFF;
// 			buffer[pixel + 2] = (color >> 8) & 0xFF;
// 			buffer[pixel + 3] = (color) & 0xFF;
// 		}
// 		else if (endian == 0)   // Least significant (Blue) byte first
// 		{
// 			buffer[pixel + 0] = (color) & 0xFF;
// 			buffer[pixel + 1] = (color >> 8) & 0xFF;
// 			buffer[pixel + 2] = (color >> 16) & 0xFF;
// 			buffer[pixel + 3] = (color >> 24);
// 		}
// 	}}
// 	if (m.img)
// 		mlx_put_image_to_window(m.m, m.mw, m.img, 20, 20);
// 	else
// 		printf("WAAAA\n");
// 	// mlx_hook(data.win, 2, 1L << 0, &on_keypress, &data);
// 	mlx_hook(m.mw, 17, 1L << 2, exitbutton, &m);
// 	mlx_loop(m.m);
// 	return (0);
// }