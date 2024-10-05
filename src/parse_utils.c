/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:16:22 by ffidha            #+#    #+#             */
/*   Updated: 2024/10/05 10:55:39 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

static double integr(char **str)
{
    double result;

    result = 0.0;
    while (**str >= '0' && **str <= '9')
    {
        result = result * 10.0 + (**str - '0');
        (*str)++;
    }
    return (result);
}

static double decml(char **str)
{
    double result;
    double dec_place;

    result = 0.0;
    dec_place = 1.0;
    if (**str == '.')
    {
        (*str)++;
        while (**str >= '0' && **str <= '9')
        {
            dec_place *= 0.1;
            result += (**str - '0') * dec_place;
            (*str)++;
        }
    }
    return (result);
}

double str_to_db(char *str)
{
    double result;
    int is_neg;

    result = 0.0;
    is_neg = 0;
    while (*str == ' ')
        str++;
    if (*str == '-')
    {
        is_neg = 1;
        str++;
    }
    result += integr(&str);
    result += decml(&str);
    if (is_neg)
        result *= -1;
    return (result);
}