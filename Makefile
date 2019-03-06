# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 17:50:38 by julee             #+#    #+#              #
#    Updated: 2018/10/23 14:50:26 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

DEBUGGER = debugger

CC = @gcc -Wall -Werror -Wextra

SRC = main.c flag.c store.c sort.c recursive.c print.c count.c cmp.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

debug: $(DEBUGGER)

$(DEBUGGER): $(SRC) $(LIB)
	$(CC) -o $(DEBUGGER) -g $(SRC) $(LIB)

$(LIB):
	@cd libft && make

clean:
	@rm -rf $(OBJ)
	@cd libft && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all
