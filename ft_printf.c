/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:32:45 by tpeters           #+#    #+#             */
/*   Updated: 2022/05/04 15:42:50 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	interpret(char *token, va_list *arg_list, int pos)
{
	int				size;
	struct s_flags	tmp;

	size = 0;
	fill_struct(&tmp, token, arg_list);
	if (token[pos] == 'c')
		size = token_c(va_arg(*arg_list, int), &tmp);
	else if (token[pos] == 's')
		size = token_s(va_arg(*arg_list, char *), &tmp);
	else if (token[pos] == 'p')
		size = token_p(va_arg(*arg_list, void *), &tmp);
	else if (token[pos] == 'd' || token[pos] == 'i')
		size = token_d(va_arg(*arg_list, int), &tmp);
	else if (token[pos] == 'u')
		size = token_u(va_arg(*arg_list, unsigned int), &tmp);
	else if (token[pos] == 'x')
		size = token_x(va_arg(*arg_list, unsigned int), &tmp, 'a');
	else if (token[pos] == 'X')
		size = token_x(va_arg(*arg_list, unsigned int), &tmp, 'A');
	else if (token[pos] == '%')
	{
		ft_putchar_fd('%', 1);
		size = 1;
	}
	return (size);
}

static int	print_char_and_return_1(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	actual_printf(const char *form, va_list *arg_list)
{
	int		size;
	char	*tmp;
	int		token_end_pos;

	size = 0;
	while (*form)
	{
		while (*form && *form != '%')
			size += print_char_and_return_1(*form++);
		if (*form == '%')
		{
			form++;
			if (*form)
			{
				token_end_pos = find_first_of(form, "cspdiuxX%");
				tmp = ft_substr(form, 0, 1 + token_end_pos);
				if (!tmp)
					return (0);
				size += interpret(tmp, arg_list, token_end_pos);
				free(tmp);
				form += token_end_pos + 1;
			}
		}
	}
	return (size);
}

int	ft_printf(const char *form, ...)
{
	va_list	arg_list;
	int		size;

	size = 0;
	va_start(arg_list, form);
	size = actual_printf(form, &arg_list);
	va_end(arg_list);
	return (size);
}
