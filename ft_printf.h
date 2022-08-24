/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:13:22 by tpeters           #+#    #+#             */
/*   Updated: 2022/08/24 17:06:48 by tpeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# ifdef _WIN32
#  define long long long
# endif

struct s_flags {
	int	minus;
	int	plus;
	int	space;
	int	hashtag;
	int	zero;
	int	ms;
	int	pr;
};

int		ft_printf(const char *form, ...);

/* FT_PRINTF_TOKENS.C */
int		token_d(int tmp, struct s_flags *flag);
int		token_s(char *tmp, struct s_flags *flag);
int		token_c(int tmp, struct s_flags *flag);
int		token_u(unsigned int tmp, struct s_flags *flag);

/* FT_PRINTF_HEXTOKENS.C */
int		token_x(unsigned int var, struct s_flags *flag, char a);
int		token_bigx(unsigned int var, struct s_flags *flag);
int		token_p(void *var, struct s_flags *flag);

/* FT_PRINTF_UTILS.C */
int		spacing(int cur_len, int min_size, char fill);
int		hex_len(unsigned long in, int precision);
int		char_in_set(char c, char const *set);
int		find_first_of(const char *c, char const *set);

/* FT_PRINTF_FLAGS.C */
void	fill_struct(struct s_flags *tmp, char *token, va_list *arg_list);

/* FT_PRINTF_PREC.C */
int		put_str_prec(char *tmp, int precision);
int		num_len(char *in);
int		str_prec(char *tmp, int precision);
int		int_prec(char *tmp, int precision);

#endif