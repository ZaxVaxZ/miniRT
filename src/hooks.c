/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:27:20 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/12 11:30:47 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	keypress_hook(int keypress, t_main *m)
{
	if (keypress == ESC)
		free_and_exit(m, 0, 0);
	return (0);
}

int	redraw(t_main *m)
{
	draw_rainbow(*m);
	return (0);
}

int	exitbutton_hook(t_main *m)
{
	free_and_exit(m, 0, 0);
	return (0);
}
