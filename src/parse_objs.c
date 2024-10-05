/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:11:53 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/05 10:54:02 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

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
	line += 1;
    parse_values(&line, scene_arr[row], 1, 3);
    parse_values(&line, scene_arr[row], 4, 3);
    parse_values(&line, scene_arr[row], 7, 1);

}

void ambient(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = AMBIENT;
    line += 1;
    parse_values(&line, scene_arr[row], 4, 1); //lighting ratio
    parse_values(&line, scene_arr[row], 9, 3);  // RGB
}

void light(char *line, double **scene_arr, int row)
{
    scene_arr[row][0] = LIGHT;
    line += 1;

    parse_values(&line, scene_arr[row], 1, 3);  // xyz
	parse_values(&line, scene_arr[row], 7, 1); // brightness
    parse_values(&line, scene_arr[row], 9, 3);  // RGB (if doing bonus)
}
