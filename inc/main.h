#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

# define HEIGHT 512
# define WIDTH 1024

typedef struct	s_main
{
	void	*mlx;
	void	*mw;
	void	*img;
}	t_main;

#endif