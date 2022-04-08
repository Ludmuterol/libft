/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:28:35 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:17:17 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*sub;
	unsigned int	tot_size;

	if (!s1 || !s2)
		return (NULL);
	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	sub = (char *) malloc (tot_size);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s1, tot_size);
	ft_strlcat(sub, s2, tot_size);
	return (sub);
}
