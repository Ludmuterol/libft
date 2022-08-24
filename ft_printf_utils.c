/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:26:32 by tpeters           #+#    #+#             */
/*   Updated: 2022/05/04 14:44:40 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spacing(int cur_len, int min_size, char fill)
{
	int		size;

	size = 0;
	while (min_size > cur_len)
	{
		ft_putchar_fd(fill, 1);
		min_size--;
		size++;
	}
	return (size);
}

int	hex_len(unsigned long in, int precision)
{
	int	len;

	len = 0;
	if (!in && precision)
		return (1);
	while (in)
	{
		in /= 16;
		len++;
	}
	if (precision > len)
		return (precision);
	return (len);
}

int	char_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	find_first_of(const char *c, char const *set)
{
	int	i;

	i = 0;
	while (c[i] && !char_in_set(c[i], set))
		i++;
	return (i);
}
