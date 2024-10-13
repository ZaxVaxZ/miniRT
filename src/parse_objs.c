/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:58:39 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/13 22:34:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_values(char **line, double *arr, int start, int count)
{
	int		i;
	int		issue;

	issue = 0;
	i = start;
	while (i < start + count)
	{
		while (**line == ' ')
			(*line)++;
		arr[i] = str_to_double(line, &issue, i < start + count - 1);
		if (i < start + count - 1 && **line == ',')
		{
			(*line)++;
			if ((**line < '0' || **line > '9') && **line != '+' && **line != '-')
				issue = 1;
		}
		else if (i < start + count - 1)
			issue = 1;
		if (issue)
			break ;
		i++;
	}
	return (issue);
}

void	parse_shape(char *line, int *i, double *scene_arr, int *issue)
{
	int	obj_type;

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
	*issue += check_end_of_line(line);
}

void	camera(char *line, double *scene_arr, int *issue)
{
	if (ft_strncmp(line, "C", 1) != 0)
		return ;
	while (*line == ' ')
		line++;
	*issue = 0;
	scene_arr[0] = CAMERA;
	line += 1;
	*issue += parse_values(&line, scene_arr, 1, 3);
	*issue += parse_values(&line, scene_arr, 4, 3);
	*issue += parse_values(&line, scene_arr, 7, 1);
	*issue += check_end_of_line(line);
}

void	ambient(char *line, double *scene_arr, int *issue)
{
	if (ft_strncmp(line, "A", 1) != 0)
		return ;
	while (*line == ' ')
		line++;
	*issue = 0;
	scene_arr[0] = AMBIENT;
	line += 1;
	*issue += parse_values(&line, scene_arr, 7, 1);
	*issue += parse_values(&line, scene_arr, 9, 3);
	*issue += check_end_of_line(line);
}

void	light(char *line, double *scene_arr, int *issue)
{
	if (ft_strncmp(line, "L", 1) != 0)
		return ;
	while (*line == ' ')
		line++;
	*issue = 0;
	scene_arr[0] = LIGHT;
	line += 1;
	*issue += parse_values(&line, scene_arr, 1, 3);
	*issue += parse_values(&line, scene_arr, 7, 1);
	*issue += parse_values(&line, scene_arr, 9, 3);
	*issue += check_end_of_line(line);
}
