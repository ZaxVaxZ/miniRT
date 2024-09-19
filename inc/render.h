/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/18 04:43:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RENDER_H
# define RENDER_H

# include "general.h"
# include "ft_math.h"
# include "mlx.h"

void	color_pixel(t_main *m, int x, int y, int color);
void	draw_rainbow(t_main *m);
void	render_scene(t_main *m);

#endif