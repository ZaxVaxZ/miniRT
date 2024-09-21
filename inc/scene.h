/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:42 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/19 12:21:17 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "general.h"
# include "ft_math.h"

void	init_scene(t_main *m, t_scene *s, double **objs);
void	setup_scene(t_main *m, t_scene *s);
void	free_scene(t_scene s);
void	count_shapes(int count[4], double **objs);
void	read_camera_values(t_camera *c, double *vals);
void	read_light_values(t_light *li, double *vals);
void	read_shape_values(t_main *m, t_object *o, double *vals);

#endif