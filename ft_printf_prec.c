/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:32 by tpeters           #+#    #+#             */
/*   Updated: 2022/05/04 14:53:38 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str_prec(char *tmp, int precision)
{
	int	count;

	count = 0;
	while ((precision >= 0 && count < precision && tmp[count])
		|| (precision < 0 && tmp[count]))
	{
		ft_putchar_fd(tmp[count], 1);
		count++;
	}
	return (count);
}

int	num_len(char *in)
{
	while (*in && !ft_isdigit(*in))
		in++;
	return (ft_strlen(in));
}

int	str_prec(char *tmp, int precision)
{
	int	a;

	a = ft_strlen(tmp);
	if (a > precision && precision >= 0)
		return (precision);
	return (a);
}

int	int_prec(char *tmp, int precision)
{
	if (num_len(tmp) < precision)
		return (ft_strlen(tmp) - num_len(tmp) + precision);
	return (ft_strlen(tmp));
}
