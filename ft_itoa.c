/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:16:19 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:15:29 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{	
	char	*p;
	int		is_neg;
	long	num;
	int		len;

	num = n;
	len = num_len(num) - 1;
	p = (char *)malloc(len + 1 + 1);
	if (!p)
		return (NULL);
	p[len + 1] = '\0';
	is_neg = (num < 0);
	if (is_neg)
		num *= -1;
	while (len > 0)
	{
		p[len] = '0' + (num % 10);
		len--;
		num /= 10;
	}
	if (is_neg)
		p[len] = '-';
	else
		p[len] = '0' + (num % 10);
	return (p);
}
