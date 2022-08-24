/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:22:41 by tpeters           #+#    #+#             */
/*   Updated: 2022/05/04 17:04:06 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_sign(char *in, char flag)
{
	char	*out;

	if (!ft_isdigit(*in) || flag == 0)
		return (in);
	if (flag == '+')
		out = ft_strjoin("+", in);
	else
		out = ft_strjoin(" ", in);
	if (!out)
		return (in);
	free(in);
	return (out);
}

int	token_d(int tmp, struct s_flags *flag)
{
	char	*out;
	int		size;

	if (!tmp && !flag->pr)
		out = ft_strdup("");
	else
		out = ft_itoa(tmp);
	if (!out)
		return (0);
	out = add_sign(out, flag->plus * '+' + flag->space * ' ');
	size = ft_strlen(out);
	if (!flag->minus && !flag->zero)
		size += spacing(int_prec(out, flag->pr), flag->ms, ' ');
	if (*out && !ft_isdigit(*out))
		ft_putchar_fd(*out, 1);
	if (!flag->minus && flag->zero)
		size += spacing(int_prec(out, flag->pr), flag->ms, '0');
	size += spacing(num_len(out), flag->pr, '0');
	if (*out)
		ft_putstr_fd(out + !ft_isdigit(*out), 1);
	free(out);
	if (flag->minus)
		size += spacing(size, flag->ms, ' ');
	return (size);
}

int	token_s(char *tmp, struct s_flags *flag)
{
	int		size;
	char	flagc;

	size = 0;
	flagc = !flag->zero * ' ' + flag->zero * '0';
	if (tmp)
	{
		if (!flag->minus)
			size += spacing(str_prec(tmp, flag->pr), flag->ms, flagc);
		put_str_prec(tmp, flag->pr);
		size += str_prec(tmp, flag->pr);
	}
	else
	{
		if (!flag->minus)
			size += spacing(str_prec("(null)", flag->pr), flag->ms, flagc);
		put_str_prec("(null)", flag->pr);
		size += str_prec("(null)", flag->pr);
	}
	if (flag->minus)
		size += spacing(size, flag->ms, ' ');
	return (size);
}

int	token_c(int tmp, struct s_flags *flag)
{
	int		size;
	char	flagc;

	size = 0;
	flagc = !flag->zero * ' ' + flag->zero * '0';
	if (!flag->minus)
		size += spacing(1, flag->ms, flagc);
	ft_putchar_fd((unsigned char)tmp, 1);
	size++;
	if (flag->minus)
		size += spacing(size, flag->ms, ' ');
	return (size);
}

int	token_u(unsigned int tmp, struct s_flags *flag)
{
	char	*out;
	int		size;
	char	flagc;

	if (!tmp && !flag->pr)
		out = ft_strdup("");
	else
		out = ft_utoa(tmp);
	if (!out)
		return (0);
	size = ft_strlen(out);
	flagc = !flag->zero * ' ' + flag->zero * '0';
	if (!flag->minus)
		size += spacing(int_prec(out, flag->pr), flag->ms, flagc);
	size += spacing(int_prec(out, -1), flag->pr, '0');
	ft_putstr_fd(out, 1);
	free(out);
	if (flag->minus)
		size += spacing(size, flag->ms, ' ');
	return (size);
}
