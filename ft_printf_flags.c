/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:11:48 by tpeters           #+#    #+#             */
/*   Updated: 2022/08/17 02:36:02 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_struct(struct s_flags *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->hashtag = 0;
	flag->zero = 0;
	flag->ms = 0;
	flag->pr = 0;
}

static int	get_min_size(char *token, va_list *arg_list, int *minus)
{
	int	pos;
	int	ms;

	pos = 0;
	while (token[pos] && token[pos] != '.' \
	&& !ft_isdigit(token[pos]) && token[pos] != '*')
		pos++;
	if (ft_isdigit(token[pos]))
		return (ft_atoi(token + pos));
	if (token[pos] == '*')
	{
		ms = va_arg(*arg_list, int);
		if (ms < 0)
		{
			ms *= -1;
			*minus = 1;
		}
		return (ms);
	}
	return (0);
}

static int	get_precision(char *token, va_list *arg_list)
{
	int	pos;

	pos = 0;
	while (token[pos] && token[pos] != '.')
		pos++;
	if (!token[pos])
		return (-1);
	pos++;
	if (ft_isdigit(token[pos]))
		return (ft_atoi(token + pos));
	if (token[pos] == '*')
		return (va_arg(*arg_list, int));
	return (0);
}

static void	check_flags(struct s_flags *tmp, char conv)
{
	if (tmp->minus)
		tmp->zero = 0;
	if (char_in_set(conv, "diuxX") && tmp->pr >= 0)
		tmp->zero = 0;
	if (tmp->plus)
		tmp->space = 0;
}

void	fill_struct(struct s_flags *tmp, char *token, va_list *arg_list)
{
	int	pos;

	init_struct(tmp);
	pos = 0;
	while (token[pos] && char_in_set(token[pos], "-+ #0"))
	{
		if (token[pos] == '-' )
			tmp->minus = 1;
		if (token[pos] == '+' )
			tmp->plus = 1;
		if (token[pos] == ' ' )
			tmp->space = 1;
		if (token[pos] == '#' )
			tmp->hashtag = 1;
		if (token[pos] == '0' && tmp->zero == 1)
			break ;
		if (token[pos] == '0' )
			tmp->zero = 1;
		pos++;
	}
	tmp->ms = get_min_size(token + pos, arg_list, &tmp->minus);
	tmp->pr = get_precision(token + pos, arg_list);
	check_flags(tmp, token[ft_strlen(token) - 1]);
}
