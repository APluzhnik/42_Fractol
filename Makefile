# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 17:06:54 by apluzhni          #+#    #+#              #
#    Updated: 2019/04/08 11:23:01 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Wextra -Werror

MLX_LNK = -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB_LNK = -L ./libft/ -lft
MAT_LNK = -lm

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/
LIB_DIR = ./libft/

SRC = main.c events.c render.c help.c init.c
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC = $(addprefix $(INC_DIR),fractol.h)
LIB = libft.a

define colorecho
	  @tput setaf $2
	  @echo $1
	  @tput sgr0
endef

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	$(call colorecho, "$(NAME): Linking files...", 3)
	@gcc -g $(FLAG) $(LIB_LNK) $(MLX_LNK) $(MAT_LNK) $(addprefix $(SRC_DIR),$(SRC)) -o $(NAME)
	$(call colorecho, "$(NAME): Complete!", 2)
	$(call colorecho, "$(NAME): Executable file (./$(NAME)) is ready!", 4)

$(LIB):
	$(call colorecho, "$(NAME): Making lib...", 4)
	$(call colorecho, "╔════════════════════════════════════╗", 6)
	@make -C ./libft/
	$(call colorecho, "╚════════════════════════════════════╝", 6)

$(OBJ_DIR):
	$(call colorecho, "$(NAME): Creating object folder...", 3)
	@mkdir $(OBJ_DIR)
	$(call colorecho, "$(NAME): Compiling source...", 3)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAG) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

clean:
	$(call colorecho, "$(NAME): Cleaning lib...", 1)
	$(call colorecho, "╔════════════════════════════════════╗", 6)
	@make -C ./libft/ clean
	$(call colorecho, "╚════════════════════════════════════╝", 6)
	$(call colorecho, "$(NAME): Deleting object files...", 1)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(call colorecho, "$(NAME): Deleting lib...", 1)
	$(call colorecho, "╔════════════════════════════════════╗", 6)
	@make -C ./libft/ fclean
	$(call colorecho, "╚════════════════════════════════════╝", 6)
	$(call colorecho, "$(NAME): Deleting exe file...", 1)
	@rm -f $(NAME)
	@rm -rf fractol.dSYM

re: fclean all

kill:
	$(call colorecho, "$(NAME): Killing proces...", 1)
	@pkill fractol
	$(call colorecho, "$(NAME): Killed!", 2)

j: re
	$(call colorecho, "$(NAME): No errors.", 2)
	$(call colorecho, "$(NAME): Start Julia...", 5)
	@./fractol Julia

m: re
	$(call colorecho, "$(NAME): No errors.", 2)
	$(call colorecho, "$(NAME): Start Mandelbrot...", 5)
	@./fractol Mandelbrot

.PHONY: clean fclean re kill
