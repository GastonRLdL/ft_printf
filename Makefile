# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 12:48:15 by groman-l          #+#    #+#              #
#    Updated: 2023/05/22 19:00:10 by groman-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
C_FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_FILES = ft_printf	ft_functions1	ft_functions2

SRC = $(addsuffix .c, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME):: $(OBJ) $(HEADER)
		ar -rcs $(NAME) $(OBJ)
		@echo "All compilated."

$(NAME)::
		 @echo "Everything ok."

.PHONY: all clean fclean re

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)
		@echo "All gone"

re: fclean all
