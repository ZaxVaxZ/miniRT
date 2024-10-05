/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/10/05 02:15:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "general.h"
# include "ft_math.h"
# include "scene.h"
# include "mlx.h"

void	color_pixel(t_main *m, int x, int y, unsigned int color);
void	draw_rainbow(t_main *m);
void	draw_grid(t_main *m, t_ray *ray, int i, int j);
void	background_gradient(t_main *m, t_ray *ray, int i, int j);
void	render_scene(t_main *m);

#endif