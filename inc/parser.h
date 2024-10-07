/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:17 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/07 11:26:04 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "general.h"

double	str_to_db(char *str);
int		open_file(t_main *m, char *file);
void	cylinder(char *line, double **scene_arr, int row);
void	sphere(char *line, double **scene_arr, int row);
void	plane(char *line, double **scene_arr, int row);
void 	light(char *line, double **scene_arr, int row);
void 	ambient(char *line, double **scene_arr, int row);
void 	camera(char *line, double **scene_arr, int row);
void 	parse_values(char **line, double *arr, int start, int count);
void	read_file(char *file, double **scene_arr);
int		find_rt(char *path);
double	**allocate_scene_array(int object_count);
int		count_objects(int fd);

#endif