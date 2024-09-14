/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:14:40 by ffidha            #+#    #+#             */
/*   Updated: 2024/09/14 11:40:22 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general.h"

int	find_scene(t_main *main, int fd)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'A')
			ambient(main, line);
		else if (line[0] == 'c' && line[1] == 'y')
			cylinder(main, line);
		else if (line[0] == 'c' && line[1] == 'a')
			camera(main, line);
		else if (line[0] == 'l')
			light(main, line);
		else if (line[0] == 's' && line[1] == 'p')
			sphere(main, line);
		else if (line[0] == 'p' && line[1] == 'l')
			plane(main, line);
		free(line);
	}
	free(line);
	return (0);
}

int	find_rt(char *path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.')
		{
			if (path[i + 1] == 'r' && path[i + 2] == 't')
				return (1);
		}
		i++;
	}
	return (0);
}

int open_file(t_main *main, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_and_exit(main, "Error\nFile not found", FAILURE);
	if (!find_rt(file))
		free_and_exit(main, "Error\nFile not a .rt", FAILURE);
	if (find_scene(fd, main) == 1)
		free_and_exit(main, "Error\nScene not found", FAILURE);
	return (0);
}
