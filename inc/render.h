/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/12 11:41:01 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RENDER_H
# define RENDER_H

# include "general.h"
# include "mlx.h"

void	color_pixel(t_main m, int x, int y, int color);
void	draw_rainbow(t_main m);

#endif