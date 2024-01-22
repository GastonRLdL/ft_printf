# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:35:28 by gasroman          #+#    #+#              #
#    Updated: 2024/01/22 16:19:51 by gasroman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== VARIABLES ================================== #

NAME	=	libftprintf.a
CC		=	gcc
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar -rcs
CURRENT_FILE = 0
#PROGRESS_BAR :=

# =========================== SOURCES ======================================== #

SRC	=	ft_printf.c		\
		ft_for_cs.c		\
		ft_for_diupx.c	\
# =========================== DIRECTORIES ==================================== #

D_OBJ = obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

# =========================== BOLD COLORS ==================================== #

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
P = \033[35m
C = \033[36m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m

# ========================== MAKE RULES ===================================== #
all:	dir $(NAME)
-include $(DEP)
-include $(B_DEP)

dir: 
	-mkdir $(D_OBJ)

#Compilation with loading bar
$(D_OBJ)/%.o: %.c
	$(CC) -MMD $(FLAGS) -c $< -o $@
	 $(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE) + 1)))) \
	 $(eval PROGRESS_BAR := $(shell awk "BEGIN { printf \"%.0f\", $(CURRENT_FILE)*100/$(TOTAL_FILES) }")) \
	 printf "\r$B$(ligth)⏳Compiling libft:$E $(ligth)%-30s [$(CURRENT_FILE)/$(TOTAL_FILES)] [%-50s] %3d%%\033[K" \
	 "$<..." "$(shell printf '$(G)█%.0s$(E)$(ligth)' {1..$(shell echo "$(PROGRESS_BAR)/2" | bc)})" $(PROGRESS_BAR)
	
	 @if [ $(PROGRESS_BAR) = 100 ]; then \
		echo "$(B) All done$(E)"; \
	fi
$(NAME):	${OBJ}
	$(LIBC) $(NAME) $(OBJ)
	touch $(NAME)
	echo "\n\n✅ ==== $(B)$(ligth)Project ft_printf compiled!$(E) ==== ✅"
# bonus:	dir ${B_OBJ} $(NAME)
# 	if [ -f bonus ]; then\
# 		echo "$(B)$(ligth)make:$(E)$(ligth) 'bonus' is up to date.$(E)";\
# 	else\
# 		$(LIBC) $(NAME) $(OBJ) $(B_OBJ);\
# 		touch bonus;\
# 		echo "$B$(ligth)⏳Compiling libft:$E";\
#	fi
# ========================== CLEAN   ===================================== #
.PHONY: all clean fclean re bonus
clean:
	$(RM) $(D_OBJ) bonus
	echo "✅ ==== $(P)$(ligth)Libft object files cleaned!$(E) ==== ✅"
fclean: clean
	$(RM) $(NAME)
	echo "✅ ==== $(P)$(ligth)Libft executable files and name cleaned!$(E) ==== ✅\n"
re: fclean all
TOTAL_FILES := $(words $(SRCS))
.SILENT: