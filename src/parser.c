/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:47:32 by marvin            #+#    #+#             */
/*   Updated: 2024/09/27 22:59:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#define BLACK	0,	   0,   0
#define WHITE	255, 255, 255
#define RED		255,   0,   0
#define GREEN	  0, 255,   0
#define BLUE	  0,   0, 255
#define CYAN	  0, 255, 255
#define PINK	255,   32, 255
#define YELLOW	255, 255,   0
#define ORANGE	255, 100,   0
#define BROWN	120,  40,   0
#define PURPLE	180,   0, 180

double	**get_objs()
{
	int		rows;
	double	**ret;

	rows = 13;
	double arr[13][12] = 
	{{CAMERA, -4,4, -4, 4, -4, 4, 100, 0,   0,   0,   0},
	 {AMBIENT, 0, 0, 0, 0, 0, 0, 0, 0.2, 255, 255, 255},
	 {LIGHT,   0, 0, 0, 0, 0, 0, 0.8, 0, 255, 255, 255},

	 {SPHERE, 1, 1, 1, 0, 0, 0, 0.5, 0, RED},
	 {SPHERE, -1, 1, -1, 0, 0, 0, 0.5, 0, GREEN},
	 {SPHERE, -1, 1, 1, 0, 0, 0, 0.5, 0, YELLOW},
	 {SPHERE, 1, 1, -1, 0, 0, 0, 0.5, 0, BLUE},
	 {SPHERE, 0, 0, 0, 0, 0, 0, 0.5, 0, WHITE},
	 {SPHERE, 1, -1, 1, 0, 0, 0, 0.5, 0, PINK},
	 {SPHERE, -1, -1, -1, 0, 0, 0, 0.5, 0, ORANGE},
	 {SPHERE, -1, -1, 1, 0, 0, 0, 0.5, 0, PURPLE},
	 {SPHERE, 1, -1, -1, 0, 0, 0, 0.5, 0, CYAN},
	 
	 {INVALID, 0, 0, 0, 0, 0, 0,   0, 0,   0,   0,   0}
	};
	ret = malloc(sizeof(double *) * rows);
	for (int i=0;i<rows;i++)
		ret[i] = malloc(sizeof(double) * 12);
	for (int i=0;i<rows;i++)
		for(int j=0;j<12;j++)
			ret[i][j] = arr[i][j];
	return (ret);
}
