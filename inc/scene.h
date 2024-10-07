/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:42 by ehammoud          #+#    #+#             */
/*   Updated: 2024/10/07 04:06:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "general.h"
# include "ft_math.h"

void	init_scene(t_main *m, t_scene *s, double **objs);
void	setup_scene(t_main *m, t_scene *s);
int		intersects(t_main *m, t_ray *ray);
void	create_shapes_arr(t_main *m, void **arr_pointer, int cnt, int shape);
void	count_shapes(int count[4], double **objs);
void	read_light_values(t_main *m, t_light *li, double *vals);
void	read_camera_values(t_main *m, t_camera *c, double *vals);
void	read_shape_values(t_main *m, t_object *o, double *vals);
int		interrupted(t_main *m, t_hit *hit);

#endif