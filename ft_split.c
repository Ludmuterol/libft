/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:11:34 by tpeters           #+#    #+#             */
/*   Updated: 2022/04/08 15:16:21 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	amount;
	int	i;

	i = 0;
	amount = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			amount++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (amount);
}

static int	get_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*free_stuff(char **p, int curr_w)
{
	while (curr_w >= 0)
	{
		free(p[curr_w]);
		curr_w--;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**p;
	int		curr_w;
	int		curr_c;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	p = (char **)malloc(sizeof(char *) * (words + 1));
	if (!p)
		return (NULL);
	curr_w = 0;
	curr_c = 0;
	while (curr_w < words)
	{
		while (s[curr_c] && s[curr_c] == c)
			curr_c++;
		p[curr_w] = ft_substr(s, curr_c, get_word_len(s + curr_c, c));
		if (!p[curr_w])
			return (free_stuff(p, curr_w - 1));
		curr_c += get_word_len(s + curr_c, c);
		curr_w++;
	}
	p[words] = NULL;
	return (p);
}
