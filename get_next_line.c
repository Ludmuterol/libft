/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tpeters <tpeters@student.42heilbronn.de	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/25 14:51:30 by tpeters		   #+#	#+#			 */
/*   Updated: 2022/04/25 14:52:02 by tpeters		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static char	*merge(char **a, char *b)
{
	char	*ret;

	if (!b)
	{
		free(*a);
		return (NULL);
	}
	ret = (char *)malloc(ft_strlen(*a) + ft_strlen(b) + 1);
	if (!ret)
		return (NULL);
	ft_memmove(ret, *a, ft_strlen(*a) + 1);
	ft_memmove(ret + ft_strlen(*a), b, ft_strlen(b) + 1);
	ret[ft_strlen(*a) + ft_strlen(b)] = '\0';
	free(*a);
	free(b);
	*a = ret;
	return (ret);
}

static unsigned int	find_n(char *ptr)
{
	unsigned int	tmp;

	tmp = 0;
	while (ptr[tmp] && ptr[tmp] != '\n')
		tmp++;
	return (tmp);
}

char	*shift_and_ret(char **ret, char *ptr)
{
	*ret = merge(ret, ft_substr(ptr, 0, find_n(ptr) + 1));
	ft_memmove(ptr, ptr + find_n(ptr) + 1, BUFFER_SIZE - find_n(ptr));
	return (*ret);
}

static char	*free_and_ret(char **ptr, char **ret)
{
	free(*ptr);
	*ptr = NULL;
	if ((*ret)[0])
		return (*ret);
	free(*ret);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*ptr[FD_SIZE];
	int				bytes_read;
	char			*ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_SIZE)
		return (NULL);
	if (!ptr[fd])
		ptr[fd] = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	ret = ft_substr("", 0, 0);
	if (!ret || !ptr[fd])
		return (NULL);
	while (1)
	{
		if (ptr[fd][find_n(ptr[fd])] == '\n')
			return (shift_and_ret(&ret, ptr[fd]));
		if (find_n(ptr[fd]) > 0)
			if (!merge(&ret, ft_substr(ptr[fd], 0, find_n(ptr[fd]) + 1)))
				return (NULL);
		bytes_read = read(fd, ptr[fd], BUFFER_SIZE);
		if (bytes_read < 1)
			break ;
		ft_memset(ptr[fd] + bytes_read, '\0', BUFFER_SIZE - bytes_read);
	}
	return (free_and_ret(&(ptr[fd]), &ret));
}
