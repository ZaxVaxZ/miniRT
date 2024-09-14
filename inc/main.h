/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/14 18:18:12 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "general.h"
# include "render.h"
# include "scene.h"

int		keypress_hook(int keypress, t_main *m);
int		exitbutton_hook(t_main *m);
int		redraw(t_main *m);

#endif