/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:48 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/12 11:42:53 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	free_and_exit(t_main *m, int msg, int status)
{
	int	ret;

	ret = 0;
	if (msg == SUCCESS)
		ret = write(1, "Execution Complete!\n", 20);
	if (msg == FAILURE)
		ret = write(2, "Error\nUnexpected Error!\n", 24);
	if (msg == ERR_MEM)
		ret = write(2, "Error\nMemory allocation failure!\n", 33);
	if (ret < 0)
		status = FAILURE;
	if (m->img && m->mlx)
		mlx_destroy_image(m->mlx, m->img);
	if (m->mw && m->mlx)
		mlx_destroy_window(m->mlx, m->mw);
	if (m->mlx)
		free(m->mlx);
	exit(status);
}
