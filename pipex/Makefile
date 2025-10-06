# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 10:30:23 by ankozako          #+#    #+#              #
#    Updated: 2025/09/22 10:30:25 by ankozako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 		= pipex
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror

LIBFT_PATH 	= lib/libft
LIBFT_A 	= $(LIBFT_PATH)/libft.a

INCLUDE		= -I inc -I $(LIBFT_PATH)

SRC = src/main.c src/errors.c src/pipex.c src/path.c src/files.c
			  
OBJ	= $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
		rm -f $(OBJ)
		-$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	-$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all