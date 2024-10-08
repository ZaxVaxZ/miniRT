/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:17 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/08 07:24:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "general.h"
# include "libft.h"

# define CAMERA 0
# define AMBIENT 1
# define LIGHT 2
# define PLANE 3
# define SPHERE 4
# define CYLINDER 5
# define DUPLICATE 6
# define SUM 7

double	str_to_double(char **str, int *issue);
double	**allocate_scene_array(t_main *m, int object_count);
double	**open_file(t_main *m, char *file);
int		check_values(double *arr, int count, double low, double high);
int		valid_values(double **arr);
void	parse_shape(char *line, int &i, double *scene_arr);
void 	light(char *line, double **scene_arr, int row);
void 	ambient(char *line, double **scene_arr, int row);
void 	camera(char *line, double **scene_arr, int row);

#endif