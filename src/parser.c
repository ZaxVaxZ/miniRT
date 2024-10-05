/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:05:30 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 11:28:21 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

int	count_objects(int fd)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	while (get_next_line(fd) > 0)
	{
		if (ft_strncmp(line, "A", 1) == 0 || ft_strncmp(line, "C", 1) == 0
			|| ft_strncmp(line, "L", 1) == 0 || ft_strncmp(line, "cy", 2) == 0
			|| ft_strncmp(line, "co", 2) == 0 || ft_strncmp(line, "sp", 2) == 0
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

// int	find_scene(t_main *m, double **scene_arr, char *line)
// {
// 	if (ft_strncmp(line, "A", 1) == 0)
// 		ambient(m, scene_arr, 12);
// 	else if (ft_strncmp(line, "C", 1) == 0)
// 		camera(m, scene_arr, 12);
// 	else if (ft_strncmp(line, "L", 1) == 0)
// 		light(m, scene_arr, 12);
// 	else if (ft_strncmp(line, "cy", 1) == 0)
// 		cylinder(m, scene_arr, 12);
// 	else if (ft_strncmp(line, "co", 1) == 0)
// 		cone(m, scene_arr, 12);
// 	else if (ft_strncmp(line, "sp", 1) == 0)
// 		sphere(m, scene_arr, 12);
// 	else if (ft_strncmp(line, "pl", 1) == 0)
// 		plane(m, scene_arr, 12);
// 	return (0);
// }

int read_file(char *line, double **scene_arr)
{
	if (ft_strncmp(line, "A", 1) == 0)
		ambient(line, scene_arr, 12);
	else if (ft_strncmp(line, "C", 1) == 0)
		camera(line, scene_arr, 12);
	else if (ft_strncmp(line, "L", 1) == 0)
		light(line, scene_arr, 12);
	else if (ft_strncmp(line, "cy", 1) == 0)
		cylinder(line, scene_arr, 12);
	else if (ft_strncmp(line, "co", 1) == 0)
		cone(line, scene_arr, 12);
	else if (ft_strncmp(line, "sp", 1) == 0)
		sphere(line, scene_arr, 12);
	else if (ft_strncmp(line, "pl", 1) == 0)
		plane(line, scene_arr, 12);
	return (0);
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

	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_and_exit(m, "File not found", EXIT_FAILURE);
	if (!find_rt(file))
		free_and_exit(m, "Invalid file format: Not a (.rt) file", 1);
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
