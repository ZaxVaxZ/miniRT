/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mods_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:17:46 by ehammoud          #+#    #+#             */
/*   Updated: 2024/09/01 16:36:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_mods(t_mods *mods, int v)
{
	if (!mods)
		return ;
	mods->sign = 0;
	mods->space = 0;
	mods->zeroed = 0;
	mods->righted = 0;
	mods->modified = 0;
	mods->prec_width = v;
	mods->field_width = v;
}

static t_mods	*extract_nums(char **s, t_mods *mods)
{
	int		i;

	i = 0;
	while ((*s)[i] >= '0' && (*s)[i] <= '9')
		i++;
	if (i <= 10)
		mods->field_width = ft_atoi(*s);
	*s += i;
	i = 0;
	if (**s == '.')
	{
		mods->zeroed = 0;
		(*s)++;
		while ((*s)[i] >= '0' && (*s)[i] <= '9')
			i++;
		if (i <= 10)
			mods->prec_width = ft_atoi(*s);
	}
	*s += i;
	return (mods);
}

// static t_mods	*end_with_zero(t_mods *m)
// {
// 	if (m->zeroed && m->field_width == -1)
// 		m->field_width 
// }

static void	parse_mods(t_mods *m, char **s)
{
	m->sign += (!(m->sign) && **s == '+' && !(m->space));
	m->space += (!(m->space) && **s == ' ' && !(m->sign));
	m->righted += (!(m->righted) && **s == '-');
	m->modified += (!(m->modified) && **s == '#');
	m->zeroed += (**s == '0' && !(m->righted));
}

t_mods	*get_mods(char **s)
{
	t_mods	*m;

	m = malloc(sizeof(t_mods));
	if (!m || !s || !(*s) || !(**s))
		return (NULL);
	if (**s == 'd' || **s == 'i' || **s == 's'
		|| **s == 'c' || **s == 'x' || **s == 'X'
		|| **s == 'p' || **s == 'u' || **s == '%')
	{
		init_mods(m, -5);
		return (m);
	}
	init_mods(m, -1);
	while (**s && **s + 1)
	{
		parse_mods(m, s);
		if ((**s >= '1' && **s <= '9') || **s == '.')
			return (extract_nums(s, m));
		else if (**s != '-' && **s != '+' && **s != ' '
			&& **s != '#' && **s != '0')
			return (m);
		(*s)++;
	}
	return (m);
}
