/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hextokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:25:01 by tpeters           #+#    #+#             */
/*   Updated: 2022/08/17 02:45:32 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ultohex(unsigned long in, char a, int precision)
{
	long			tmp;
	int				size;
	unsigned int	c;

	tmp = (sizeof(in) * 8) - 4;
	if (!precision && !in)
		return (0);
	while (tmp && in >> tmp == 0)
		tmp -= 4;
	size = 0;
	while (tmp >= 0)
	{
		c = (in & (0b1111ULL << tmp)) >> tmp;
		ft_putchar_fd(c + (c < 10) * '0' + (c > 9) * (a - 10), 1);
		size++;
		tmp -= 4;
	}
	return (size);
}

int	token_x(unsigned int var, struct s_flags *f, char a)
{
	int	size;

	size = 0;
	if (f->hashtag && var)
	{
		if (!f->minus && !f->zero)
			size += spacing(hex_len(var, f->pr) + 2, f->ms, ' ');
		if (a == 'a')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		size += 2;
		if (!f->minus && f->zero)
			size += spacing(hex_len(var, f->pr) + 2, f->ms, '0');
	}
	else
		if (!f->minus)
			size += spacing(hex_len(var, f->pr) + (!var && f->pr > 0) \
					* (f->pr - 1), f->ms, 32 + f->zero * 16);
	size += spacing(hex_len(var, -1), f->pr, '0');
	size += ultohex(var, a, f->pr);
	if (f->minus)
		size += spacing(size, f->ms, ' ');
	return (size);
}

int	token_p(void *var, struct s_flags *flag)
{
	int	size;

	size = 0;
	if (!flag->minus && !flag->zero)
		size += spacing(hex_len((unsigned long)var, -1) + 2, flag->ms, ' ');
	ft_putstr_fd("0x", 1);
	if (!flag->minus && flag->zero)
		size += spacing(hex_len((unsigned long)var, -1) + 2, flag->ms, '0');
	size += 2 + ultohex((unsigned long)var, 'a', -1);
	if (flag->minus)
		size += spacing(size, flag->ms, ' ');
	return (size);
}
