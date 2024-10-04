/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:11:53 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/04 13:17:24 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general.h"
#include "../inc/libft.h"

#include <stdlib.h>
#include <string.h>

static void skip_spaces(char **line)
{
    while (**line == ' ')
        (*line)++;
}

void parse_values(char **line, double *arr, int start, int count)
{
    int i;
	char *trimmed;

    i = start;
    while (i < start + count)
    { 
		skip_spaces(line);
		trimmed = ft_strtrim(*line, " ");
		arr[i] = str_to_db(trimmed);
		free(trimmed);
		skip_spaces(line);
        i++;
    }
}

void camera(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = CAMERA;
    parse_values(&line, scene_arr[row], 1, 7); // Read x, y, z, orientation, FOV
}

void ambient(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = AMBIENT;    // Set object type
    line += 1;                      // Skip 'A'
    parse_values(&line, scene_arr[row], 4, 1);  // Brightness (1 value)
    parse_values(&line, scene_arr[row], 9, 3);  // Color (3 values)
}

void light(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = LIGHT;      // Set object type
    line += 1;                      // Skip 'L'

    parse_values(&line, scene_arr[row], 1, 3);  // Position (x, y, z)
    parse_values(&line, scene_arr[row], 7, 1);
    parse_values(&line, scene_arr[row], 9, 3);  // Color (3 values)
}

void cylinder(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = CYLINDER;   // Set object type
    line += 2;                      // Skip 'cy'

    parse_values(&line, scene_arr[row], 1, 3);  // Position (x, y, z)
    parse_values(&line, scene_arr[row], 4, 3);  // Orientation (x, y, z)
    parse_values(&line, scene_arr[row], 7, 1);  // Radius (1 value)
    parse_values(&line, scene_arr[row], 8, 1);  // Height (1 value)
    parse_values(&line, scene_arr[row], 9, 3);  // Color (3 values)
}

// sphere
//plane 
//cone