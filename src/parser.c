/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/07 11:26:35 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_objects(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		if (ft_strncmp(line, "A", 1) == 0 || ft_strncmp(line, "C", 1) == 0
			|| ft_strncmp(line, "L", 1) == 0 || ft_strncmp(line, "cy", 2) == 0
			|| ft_strncmp(line, "sp", 2) == 0
			|| ft_strncmp(line, "pl", 2) == 0)
			count++;
		free(line);
	}
	return (count);
}

double	**allocate_scene_array(int object_count)
{
	double	**scene_arr;
	int		i;

	i = 0;
	scene_arr = (double **)malloc(sizeof(double *) * object_count);
	if (!scene_arr)
		return (NULL);
	while (i < object_count)
	{
		scene_arr[i] = malloc(sizeof(double) * 12);
		i++;
	}
	return (scene_arr);
}

void	read_file(char *file, double **scene_arr)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "A", 1) == 0)
			ambient(line, &scene_arr[i++], 12);
		else if (ft_strncmp(line, "C", 1) == 0)
			camera(line, &scene_arr[i++], 12);
		else if (ft_strncmp(line, "L", 1) == 0)
			light(line, &scene_arr[i++], 12);
		else if (ft_strncmp(line, "cy", 2) == 0)
			cylinder(line, &scene_arr[i++], 12);
		else if (ft_strncmp(line, "sp", 2) == 0)
			sphere(line, &scene_arr[i++], 12);
		else if (ft_strncmp(line, "pl", 2) == 0)
			plane(line, &scene_arr[i++], 12);
		free(line);
	}
	close(fd);
}

int	find_rt(char *path)
{
	size_t	i;

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

int	open_file(t_main *m, char *file)
{
	int		fd;
	int		count;
	double	**scene_arr;
	(void) m;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_and_exit(m, "File not found", EXIT_FAILURE);
	if (!find_rt(file))
		return (0);
	count = count_objects(fd);
	if (count <= 0)
		free_and_exit(m, "No valid objects in the file", 1);
	scene_arr = allocate_scene_array(count);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_and_exit(m, "File not found on second open", EXIT_FAILURE);
	close(fd);
	read_file(file, scene_arr);
	return (0);
}