/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:47:32 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 00:39:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

double	**get_objs()
{
	int		rows;
	double	**ret;

	rows = 5;
	double arr[5][12] = 
	{{CAMERA,  0, 0, 5, 0, 0,-1,  85, 0,   0,   0,   0},
	 {AMBIENT, 0, 0, 0, 0, 0, 0, 0.2, 0, 255, 255, 255},
	 {LIGHT,   0, 0, 0, 0, 0, 0, 0.5, 0, 255, 255, 255},

	 {SPHERE, -4, 0, 0, 0, 0, 0, 0.4, 0, 255,   0, 255},
	 
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
