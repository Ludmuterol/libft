/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:18:31 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:18:08 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	start_check;
	unsigned int	size;

	if (!s)
		return (NULL);
	start_check = 0;
	while (s[start_check] && start_check <= start)
		start_check++;
	size = 0;
	if (start_check == start + 1)
		while (s[start + size] && size < len)
			size++;
	sub = (char *) malloc(size + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}
