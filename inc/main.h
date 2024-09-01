#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

# define HEIGHT 512
# define WIDTH 1024
# define ESC 65307
# define SUCCESS 0
# define FAILURE 1
# define ERR_MEM 2

typedef struct	s_main
{
	void	*mlx;
	void	*mw;
	void	*img;
	char	*pixel;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_main;

#endif