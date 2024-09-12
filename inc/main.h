/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/12 11:17:58 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

# define HEIGHT 512
# define WIDTH 1024
# define ESC 53
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