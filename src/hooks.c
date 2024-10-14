/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:27:20 by ehammoud          #+#    #+#             */
/*   Updated: 2024/10/14 14:22:40 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	keypress_hook(int keypress, t_main *m)
{
	if (keypress == ESC)
		free_and_exit(m, "Execution Complete!", EXIT_SUCCESS);
	return (0);
}

int	redraw(t_main *m)
{
	render_scene(m);
	return (0);
}

int	exitbutton_hook(t_main *m)
{
	free_and_exit(m, "Execution Complete!", EXIT_SUCCESS);
	return (0);
}
