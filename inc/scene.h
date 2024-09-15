/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:42 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/15 20:38:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "general.h"
# include "matrix.h"

void	init_scene(t_scene *s);
void	setup_scene(t_main *m, double **objs);
void	read_camera_values(t_camera *c, double *vals);
void	read_light_values(t_light *li, double *vals);
void	read_shape_values(t_main *m, t_object *o, double *vals);

#endif