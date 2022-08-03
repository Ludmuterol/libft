/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:52:55 by tpeters           #+#    #+#             */
/*   Updated: 2022/08/03 17:13:38 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	neg_check(char **nptr)
{
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
		{
			*nptr += 1;
			return (1);
		}
		*nptr += 1;
	}
	return (0);
}

static long	ten_pow(int count)
{
	long	tmp;

	tmp = 1;
	while (count > 0)
	{
		tmp *= 10;
		count--;
	}
	return (tmp);
}

static int	ret_and_set_err(int *err, int errval)
{
	*err = errval;
	return (0);
}

double	ft_atod(char *nptr, int *err)
{
	double		i;
	int			is_neg;
	double		part;
	int			counter;

	is_neg = neg_check(&nptr);
	i = 0;
	while (ft_isdigit(*nptr))
		i = i * 10 + *nptr++ - '0';
	if (*nptr++ != '.')
		ret_and_set_err(err, 1);
	part = 0;
	counter = 0;
	while (ft_isdigit(*nptr))
	{
		part = part * 10 + *nptr - '0';
		nptr++;
		counter++;
	}
	if (*nptr != '\0')
		ret_and_set_err(err, 1);
	i += part / ten_pow(counter);
	if (is_neg)
		i *= -1;
	return (i);
}
