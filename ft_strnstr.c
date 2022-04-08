/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:26:44 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:17:28 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	if (!(*little))
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		while (little[i] && len - i && big[i] == little[i])
			i++;
		if (i == ft_strlen(little))
			return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}
