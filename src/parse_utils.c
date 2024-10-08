/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:03:36 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/08 07:23:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_values(double *arr, int count, double low, double high)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (arr[i] < low || arr[i] > high)
			return (1);
		i++;
	}
	return (0);
}

int	valid_values(double **arr)
{
	int	i;
	int	j;
	int	issues;

	issues = check_values(arr[0] + 3, 3, -1, 1);
	issues += check_values(arr[0] + 6, 1, 0, 180);
	issues += check_values(arr[1] + 6, 1, 0, 1);
	issues += check_values(arr[1] + 8, 3, 0, 255);
	issues += check_values(arr[2] + 6, 1, 0, 1);
	issues += check_values(arr[2] + 8, 3, 0, 255);
	i = 3;
	while (!issues && arr[i] && arr[i][0] != INVALID)
	{
		if (arr[i][0] != SPHERE)
			issues += check_values(arr[0] + 3, 3, -1, 1);
		issues += check_values(arr[2] + 8, 3, 0, 255);
	}
	return (issues);
}

double	**allocate_scene_array(t_main *m, int object_count)
{
	double	**scene_arr;
	int		i;
	int		j;

	i = 0;
	scene_arr = malloc(sizeof(double *) * object_count);
	if (!scene_arr)
		free_and_exit(m, ERR_MEM, EXIT_FAILURE);
	while (i < object_count)
	{
		scene_arr[i] = malloc(sizeof(double) * 12);
		if (!scene_arr[i])
		{
			free_double_array(scene_arr);
			free_and_exit(m, ERR_MEM, EXIT_FAILURE);
		}
		j = -1;
		while (++j < 12)
			scene_arr[i][j] = 0;
		i++;
	}
	return (scene_arr);
}

double	str_to_double(char **str, int *issue)
{
	double	result;
	double	decimal;
	int 	sign;

	result = 0.0;
	decimal = 1;
	sign = 1 - 2 * (**str == '-');
	*str += (**str == '-');
	while (**str >= '0' && **str <= '9')
		result = result * 10.0 + (*(*str++) - '0');
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			decimal *= 0.1;
			result += (*(*str++) - '0') * decimal;
		}
	}
	if (**str != ' ' && **str != '\0')
		*issue = 1;
	return (sign * result);
}