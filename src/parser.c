/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/09 16:25:33 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_line(char *line, int vals[8])
{
	if (vals[DUPLICATE])
		return ;
	while (*line == ' ')
		line++;
	vals[CAMERA] += (ft_strncmp(line, "C", 1) == 0);
	vals[AMBIENT] += (ft_strncmp(line, "A", 1) == 0);
	vals[LIGHT] += (ft_strncmp(line, "L", 1) == 0);
	vals[PLANE] += (ft_strncmp(line, "pl", 2) == 0);
	vals[SPHERE] += (ft_strncmp(line, "sp", 2) == 0);
	vals[CYLINDER] += (ft_strncmp(line, "cy", 2) == 0);
	if ((!(ft_strncmp(line, "sp", 2) == 0 || ft_strncmp(line, "pl", 2) == 0
			|| ft_strncmp(line, "L", 1) == 0 || ft_strncmp(line, "cy", 2) == 0
			|| ft_strncmp(line, "A", 1) == 0 || ft_strncmp(line, "C", 1) == 0))
			|| vals[CAMERA] > 1 || vals[AMBIENT] > 1 || vals[LIGHT] > 1)
		vals[DUPLICATE] = 1;
}

static int	count_objects(int fd)
{
	int		i;
	int		vals[8];
	char	*line;

	i = -1;
	while (++i < 8)
		vals[i] = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_line(line, vals);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (vals[DUPLICATE])
		free_and_exit(NULL, "Invalid file formatting", EXIT_FAILURE);
	i = -1;
	while (++i < 6)
		vals[SUM] += vals[i];
	return (vals[SUM] + 1);
}

static int	read_file(int fd, double **scene_arr)
{
	char	*line;
	int		i;
	int		issue;

	issue = 0;
	i = 3;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] && line[0] != '\n' && line[0] != '\0')
		{
			camera(line, scene_arr[0], &issue);
			ambient(line, scene_arr[1], &issue);
			light(line, scene_arr[2], &issue);
			parse_shape(line, &i, scene_arr[i], &issue);
		}
		free(line);
		line = get_next_line(fd);
	}
	issue = 0;
	close(fd);
	return (issue);
}

static void	validate_file(char *file, int *fd)
{
	size_t	len;

	if (!file || !*file)
		free_and_exit(NULL, "File name empty or doesn't exist!", EXIT_FAILURE);
	len = ft_strlen(file);
	if (len < 3 || file[len - 3] != '.'
		|| file[len - 2] != 'r' || file[len - 1] != 't')
		free_and_exit(NULL, "Specified file is not a .rt file!", EXIT_FAILURE);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		free_and_exit(NULL, "Couldn't open specified file!", EXIT_FAILURE);
}

double	**open_file(char *file)
{
	int		fd;
	int		count;
	double	**scene_arr;

	validate_file(file, &fd);
	count = count_objects(fd);
	scene_arr = allocate_scene_array(count);
	fd = open(file, O_RDONLY);
	if (fd < 0 || read_file(fd, scene_arr) != 0 || valid_values(scene_arr))
	{
		if (fd >= 0)
			close(fd);
		free_double_array(scene_arr);
		free_and_exit(NULL, "Problem while parsing file", EXIT_FAILURE);
	}
	return (scene_arr);
}
