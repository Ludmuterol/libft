/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:46:57 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:16:19 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_digit(char *c, long n)
{
	int	zeros;

	zeros = 0;
	while (n >= 10)
	{
		if (n % 10 == 0)
			zeros++;
		else
			zeros = 0;
		n /= 10;
	}
	*c = n + '0';
	return (zeros);
}

static int	num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static long	one_with_n_zeros(int n)
{
	long	i;

	i = 1;
	while (n)
	{
		i *= 10;
		n--;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;
	int		zeros;

	if (n == 0)
		write(fd, "0", 1);
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	while (num)
	{
		zeros = first_digit(&c, num);
		write(fd, &c, 1);
		while (zeros)
		{
			write(fd, "0", 1);
			zeros--;
		}
		num = num % one_with_n_zeros(num_len(num) - 1);
	}
}
