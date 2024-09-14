/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:48 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/14 16:55:23 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	free_and_exit(t_main *m, char *msg, int status)
{
	if (status && printf("Error\n") < 0)
		status = EXIT_FAILURE;
	if (printf("%s\n", msg) < 0)
		status = EXIT_FAILURE;
	if (m->img && m->mlx)
		mlx_destroy_image(m->mlx, m->img);
	if (m->mw && m->mlx)
		mlx_destroy_window(m->mlx, m->mw);
	if (m->mlx)
		free(m->mlx);
	exit(status);
}