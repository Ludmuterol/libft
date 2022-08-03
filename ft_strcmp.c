/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:59:54 by tpeters           #+#    #+#             */
/*   Updated: 2022/08/03 15:00:39 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *a, char *b)
{
	if (!a || !b)
		return (-1);
	if (ft_strlen(a) != ft_strlen(b))
		return (1);
	return (ft_strncmp(a, b, ft_strlen(a)));
}
