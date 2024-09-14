// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   object.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/10 16:10:28 by ehammoud          #+#    #+#             */
// /*   Updated: 2024/09/12 10:40:54 by ehammoud         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "scene.h"

void	init_scene(t_scene *s)
{
	if (!s)
		return ;
	s->cones = NULL;
	s->planes = NULL;
	s->spheres = NULL;
	s->cylinders = NULL;
	s->camera.fov = 100;
	s->camera.origin.x = 0;
	s->camera.origin.y = 0;
	s->camera.origin.z = -1;
	s->camera.direct.x = 0;
	s->camera.direct.y = 0;
	s->camera.direct.z = 1;
}

void	setup_scene(t_scene *s, double **objs)
{
	(void)s;(void)objs;
}

