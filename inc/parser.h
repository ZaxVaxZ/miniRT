/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:24 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/05 10:54:38 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "general.h"
#include "get_next_line.h"
#include "libft.h"

int		count_objects(int fd);
double	**allocate_scene_array(int object_count);
int		find_scene(t_main *m, char *line);
int		find_rt(char *path);
int		open_file(t_main *m, char *file);

double	str_to_db(char *str);

void	parse_values(char **line, double *arr, int start, int count);
void	camera(char *line, double **scene_arr, int row);
void	ambient(char *line, double **scene_arr, int row);
void	light(char *line, double **scene_arr, int row);
void	cylinder(char *line, double **scene_arr, int row);
void	sphere(char *line, double **scene_arr, int row);
void	plane(char *line, double **scene_arr, int row);
void	cone(char *line, double **scene_arr, int row);

#endif