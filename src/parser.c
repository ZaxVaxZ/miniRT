/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:14:40 by ffidha            #+#    #+#             */
/*   Updated: 2024/09/14 18:04:37 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "get_next_line.h"

int	find_scene(t_main *m, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'A')
			ambient(m, line);
		else if (line[0] == 'C')
			camera(m, line);
		else if (line[0] == 'L')
			light(m, line);
		else if (line[0] == 'c' && line[1] == 'y')
			cylinder(m, line);
		else if (line[0] == 'c' && line[1] == 'o')
			cone(m, line);
		else if (line[0] == 's' && line[1] == 'p')
			sphere(m, line);
		else if (line[0] == 'p' && line[1] == 'l')
			plane(m, line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	find_rt(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.' && i < ft_strlen(path) - 2)
		{
			if (path[i + 1] == 'r' && path[i + 2] == 't' && !path[i + 3])
				return (1);
		}
		i++;
	}
	return (0);
}

int open_file(t_main *m, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_and_exit(m, "File not found", EXIT_FAILURE);
	if (!find_rt(file))
		free_and_exit(m, "Invalid file format: Not a (.rt) file", 1);
	if (find_scene(fd, m) == 1)
		free_and_exit(m, "Scene not found", EXIT_FAILURE);
	return (0);
}
