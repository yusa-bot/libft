/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:20:12 by ayusa             #+#    #+#             */
/*   Updated: 2026/04/16 18:20:19 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atod_fraction(const char *str)
{
	double	result;
	double	div;

	result = 0.0;
	div = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') / div;
		div *= 10.0;
		str++;
	}
	return (result);
}

double	ft_atod(const char *str)
{
	double	result;
	int		sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		result += ft_atod_fraction(str + 1);
	return (result * sign);
}
