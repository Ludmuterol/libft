# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpeters <tpeters@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 17:11:21 by tpeters           #+#    #+#              #
#    Updated: 2023/01/09 20:10:02 by tpeters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
get_next_line.c ft_strcmp.c ft_atod.c ft_printf.c ft_printf_flags.c \
ft_printf_hextokens.c ft_printf_prec.c ft_printf_tokens.c ft_printf_utils.c \
ft_utoa.c char_in_set.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = libft.a
CFLAGS =-Wall -Wextra -Werror

ifeq ($(OS),Windows_NT)
RM_FUNC = del 
CC = gcc
else
RM_FUNC = rm
CC = cc
endif

all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)

clean :
	$(RM_FUNC) -f $(OBJS) $(BOBJS)

fclean : clean
	$(RM_FUNC) -f $(NAME)

re: fclean
	$(MAKE)

bonus : $(OBJS) $(BOBJS)
	ar cr $(NAME) $(OBJS) $(BOBJS)

.PHONY: all clean fclean re bonus