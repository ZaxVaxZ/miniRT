/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:54:17 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/05 10:54:27 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

void cylinder(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = CYLINDER;   // Set object type
    line += 2;                      // Skip 'cy'

    parse_values(&line, scene_arr[row], 1, 3);  // xyz
    parse_values(&line, scene_arr[row], 4, 3);  // 3d normalized normal vector
    parse_values(&line, scene_arr[row], 7, 1);  // diameter
    parse_values(&line, scene_arr[row], 8, 1);  // Height 
    parse_values(&line, scene_arr[row], 9, 3);  // RGB
}

void	sphere(char *line, double **scene_arr, int row)
{
	scene_arr[row][0] = SPHERE;
	line += 2;
	
	parse_values(&line, scene_arr[row], 1, 3); //position
	parse_values(&line, scene_arr[row], 7, 1); //diameter
	parse_values(&line, scene_arr[row], 8, 3); //color
}

void	plane(char *line, double **scene_arr, int row)
{
	scene_arr[row][0] = PLANE;
	line += 2;
	
	parse_values(&line, scene_arr[row], 1, 3); // position
	parse_values(&line, scene_arr[row], 4, 3); // orientation
	parse_values(&line, scene_arr[row], 7, 3); // RGB
}

void	cone(char *line, double **scene_arr, int row)
{
	scene_arr[row][0] = CONE;
	line += 2;
	
	parse_values(&line, scene_arr[row], 1, 3); // position
	parse_values(&line, scene_arr[row], 4, 3); // orientation
	parse_values(&line, scene_arr[row], 7, 1); // diameter
	parse_values(&line, scene_arr[row], 8, 1); // height
	parse_values(&line, scene_arr[row], 9, 3); // RGB
}