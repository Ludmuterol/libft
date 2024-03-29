/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:44:24 by tpeters           #+#    #+#             */
/*   Updated: 2022/09/17 13:09:24 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	first;
	unsigned int	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first])
	{
		if (!char_in_set(s1[first], set))
			break ;
		first++;
	}
	while (last >= first && last > 0)
	{
		if (!char_in_set(s1[last - 1], set))
			break ;
		last--;
	}
	return (ft_substr(s1, first, last - first));
}
