/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:27:20 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/22 02:40:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	keypress_hook(int keypress, t_main *m)
{
	if (keypress == ESC || keypress == 65307)
		free_and_exit(m, "Execution Complete!", EXIT_SUCCESS);
	return (0);
}

int	redraw(t_main *m)
{
	(void)m;
	return (0);
}

int	exitbutton_hook(t_main *m)
{
	free_and_exit(m, "Execution Complete!", EXIT_SUCCESS);
	return (0);
}
