/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:28:10 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:16:14 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	tmp;

	tmp = 0;
	while (tmp < n)
	{
		((unsigned char *)s)[tmp] = (unsigned char) c;
		tmp++;
	}
	return (s);
}
