# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 23:10:05 by julee             #+#    #+#              #
#    Updated: 2018/10/23 14:55:12 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
	  ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strncmp.c ft_strcmp.c \
	  ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strlen.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strstr.c ft_strnstr.c ft_strchr.c \
	  ft_strrchr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c \
	  ft_memcpy.c ft_bzero.c ft_memset.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c  ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd.c ft_lstmap.c \
	  ft_lstdel.c ft_lstiter.c ft_lstdelone.c \

PFSRC = printf/conversion_c.c printf/conversion_i.c printf/conversion_o.c \
		printf/conversion_p.c printf/conversion_pcnt.c printf/conversion_s.c \
		printf/conversion_u.c printf/conversion_x.c printf/flag.c printf/itoa.c \
		printf/globalfunc.c printf/ft_printf.c

OBJ = $(SRC:.c=.o)

PFOBJ = $(PFSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(PFOBJ)
	@ar -rc libft.a $(OBJ) $(PFOBJ)
	@ranlib libft.a

clean:
	@rm -f $(OBJ) $(PFOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
