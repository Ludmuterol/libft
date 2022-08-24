/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:08:17 by tpeters           #+#    #+#             */
/*   Updated: 2022/05/04 14:45:19 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	utoa_num_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{	
	char	*p;
	int		len;

	len = utoa_num_len(n) - 1;
	p = (char *)malloc(len + 1 + 1);
	if (!p)
		return (0);
	p[len + 1] = '\0';
	while (len > 0)
	{
		p[len] = '0' + (n % 10);
		len--;
		n /= 10;
	}
	p[len] = '0' + (n % 10);
	return (p);
}
