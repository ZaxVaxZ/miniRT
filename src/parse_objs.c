/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:58:39 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/09 15:15:33 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int parse_values(char **line, double *arr, int start, int count)
{
	int		i;
	int		issue;

	issue = 0;
	i = start;
	while (i < start + count)
	{ 
		while (**line == ' ')
			(*line)++;
		arr[i] = str_to_double(line, &issue);
		if (issue)
			break ;
		i++;
	}
	return (issue);
}

void parse_shape(char *line, int *i, double *scene_arr, int *issue)
{
	int obj_type;

	if (*issue)
		return ;
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "cy", 2) == 0)
		obj_type = CYLINDER;
	else if (ft_strncmp(line, "sp", 2) == 0)
		obj_type = SPHERE;
	else if (ft_strncmp(line, "pl", 2) == 0)
		obj_type = PLANE;
	else
		return ;
	(*i)++;
	scene_arr[0] = obj_type;
	line += 2;
	*issue += parse_values(&line, scene_arr, 1, 3);
	if (obj_type != SPHERE)
		*issue += parse_values(&line, scene_arr, 4, 3);
	if (obj_type != PLANE)
		*issue += parse_values(&line, scene_arr, 7, 1);
	if (obj_type != SPHERE && obj_type != PLANE)
		*issue += parse_values(&line, scene_arr, 8, 1);
	*issue += parse_values(&line, scene_arr, 9, 3);
}

void camera(char *line, double *scene_arr, int *issue)
{
	if (ft_strncmp(line, "C", 1) != 0)
		return ;
	*issue = 0;
	scene_arr[0] = CAMERA;
	line += 1;
	*issue += parse_values(&line, scene_arr, 1, 3);
	*issue += parse_values(&line, scene_arr, 4, 3);
	*issue += parse_values(&line, scene_arr, 7, 1);
}

void ambient(char *line, double *scene_arr, int *issue)
{
	if (ft_strncmp(line, "A", 1) != 0)
		return ;
	*issue = 0;
	scene_arr[0] = AMBIENT;
	line += 1;
	*issue += parse_values(&line, scene_arr, 4, 1);
	*issue += parse_values(&line, scene_arr, 9, 3);
}

void light(char *line, double *scene_arr, int *issue)
{
	if (ft_strncmp(line, "L", 1) != 0)
		return ;
	*issue = 0;
	scene_arr[0] = LIGHT;
	line += 1;
	*issue += parse_values(&line, scene_arr, 1, 3);
	*issue += parse_values(&line, scene_arr, 7, 1);
	*issue += parse_values(&line, scene_arr, 9, 3);
}
