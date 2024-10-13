/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:17 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/13 19:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "general.h"
# include "libft.h"
# include "get_next_line.h"

# define DUPLICATE 6
# define SUM 7

double	str_to_double(char **str, int *issue, int more);
double	**allocate_scene_array(int object_count);
double	**open_file(char *file);
int		check_values(double *arr, int count, double low, double high);
int		valid_values(double **arr);
int		check_end_of_line(char *line);
void	parse_shape(char *line, int *i, double *scene_arr, int *issue);
void	light(char *line, double *scene_arr, int *issue);
void	ambient(char *line, double *scene_arr, int *issue);
void	camera(char *line, double *scene_arr, int *issue);

#endif