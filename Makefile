# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 17:06:54 by apluzhni          #+#    #+#              #
#    Updated: 2019/04/18 15:24:59 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re kill help

NAME = fractol

FLAG = -Wall -Wextra -Werror

MLX_LNK = -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB_LNK = -L ./libft/ -lft
MAT_LNK = -lm

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/
LIB_DIR = ./libft/

SRC = main.c init.c \
	  menu.c menu_text.c \
	  render.c effects.c \
	  event_keys.c event_mouse.c \
	  fractal1.c fractal2.c fractal3.c
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC = $(addprefix $(INC_DIR),fractol.h)
LIB = libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@echo "\033[1;34m$(NAME): \033[5;36mLinking files...\033[0m"
	@gcc -g $(FLAG) $(LIB_LNK) $(MLX_LNK) $(MAT_LNK) $(addprefix $(SRC_DIR),$(SRC)) -o $(NAME)
	@echo "\033[1;34m$(NAME): \033[32mComplete!\033[0m"
	@echo "\033[1;34m$(NAME): \033[32mExecutable file is ready!\033[0m"
	@echo "\033[1;33mUsage: ./$(NAME) <Fractal_name>\033[0m"

$(LIB):
	@echo "\033[1;34m$(NAME): \033[5;36mMaking lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C ./libft/
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"

$(OBJ_DIR):
	@echo "\033[1;34m$(NAME): \033[5;36mCreating object folder...\033[0m"
	@mkdir $(OBJ_DIR)
	@echo "\033[1;34m$(NAME): \033[5;36mCompiling source...\033[0m"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAG) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

clean:
	@echo "\033[1;34m$(NAME): \033[5;31mCleaning lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C ./libft/ clean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;34m$(NAME): \033[32mCleaned!\033[0m"

fclean: clean
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting lib...\033[0m"
	@echo "\033[1;35m╔════════════════════════════════════╗\033[0m"
	@make -C ./libft/ fclean
	@echo "\033[1;35m╚════════════════════════════════════╝\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;31mDeleting exe file...\033[0m"
	@rm -f $(NAME)
	@rm -rf fractol.dSYM
	@echo "\033[1;34m$(NAME): \033[32mDeleted!\033[0m"

re: fclean all

kill:
	@echo "\033[1;34m$(NAME): \033[5;31mKilling proces...\033[0m"
	@pkill fractol
	@echo "\033[1;34m$(NAME): \033[32mKilled!\033[0m"

help:
	@echo "\033[1;34m~~~ Fract'ols list ~~~\033[0m"
	@echo "\033[1;34m1.\033[33m  Julia\033[0m"
	@echo "\033[1;34m2.\033[33m  Mandelbrot\033[0m"
	@echo "\033[1;34m3.\033[33m  Rhombus\033[0m"
	@echo "\033[1;34m4.\033[33m  Signal\033[0m"
	@echo "\033[1;34m5.\033[33m  Shell\033[0m"
	@echo "\033[1;34m6.\033[33m  Skull\033[0m"
	@echo "\033[1;34m7.\033[33m  Onion\033[0m"
	@echo "\033[1;34m8.\033[33m  Hazard\033[0m"
	@echo "\033[1;34m9.\033[33m  Web\033[0m"
	@echo "\033[1;34m10.\033[33m Rings\033[0m"
	@echo "\033[1;34m10.\033[33m Smoke\033[0m"
	@echo "\033[1;34m10.\033[33m MilkyWay\033[0m"

j: re
	@echo "\033[1;34m$(NAME): \033[32mNo errors.\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;32mStart Julia...\033[0m"
	@./fractol Julia

m: re
	@echo "\033[1;34m$(NAME): \033[32mNo errors.\033[0m"
	@echo "\033[1;34m$(NAME): \033[5;32mStart Mandelbrot...\033[0m"
	@./fractol Mandelbrot
