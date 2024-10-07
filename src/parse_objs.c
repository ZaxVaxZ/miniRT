/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:58:39 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/07 09:59:09 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	line += 1;
    parse_values(&line, scene_arr[row], 1, 3);
    parse_values(&line, scene_arr[row], 4, 3);
    parse_values(&line, scene_arr[row], 7, 1);
}

void ambient(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = AMBIENT;    // Set object type
    line += 1;                      // Skip 'A'
    parse_values(&line, scene_arr[row], 4, 1);  // Brightness (1 value)
    parse_values(&line, scene_arr[row], 9, 3);  // Color (3 values)
    scene_arr[row][0] = AMBIENT;
    line += 1;
    parse_values(&line, scene_arr[row], 4, 1); //lighting ratio
    parse_values(&line, scene_arr[row], 9, 3);  // RGB
}

void light(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = LIGHT;      // Set object type
    line += 1;                      // Skip 'L'
    scene_arr[row][0] = LIGHT;
    line += 1;

    parse_values(&line, scene_arr[row], 1, 3);  // Position (x, y, z)
    parse_values(&line, scene_arr[row], 7, 1);
    parse_values(&line, scene_arr[row], 9, 3);  // Color (3 values)
    parse_values(&line, scene_arr[row], 1, 3);  // xyz
	parse_values(&line, scene_arr[row], 7, 1); // brightness
    parse_values(&line, scene_arr[row], 9, 3);  // RGB (if doing bonus)
}