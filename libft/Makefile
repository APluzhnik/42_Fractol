# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 15:08:34 by apluzhni          #+#    #+#              #
#    Updated: 2019/04/06 15:55:24 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror -c -I

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

INC = $(addprefix $(INC_DIR),$(addsuffix .h,$(HEADERS))
OBJ = $(addprefix $(OBJ_DIR),$(addsuffix .o,$(FILES)))
SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(FILES)))

FILES = ft_memset ft_bzero ft_memcpy \
		ft_memccpy ft_memmove ft_memchr \
		ft_memcmp ft_strlen ft_strdup \
		ft_strcpy ft_strncpy ft_strcat \
		ft_strncat ft_strlcat ft_strchr \
		ft_strrchr ft_strstr ft_strnstr \
		ft_strcmp ft_strncmp ft_atoi \
		ft_isalpha ft_isdigit ft_isalnum \
		ft_isascii ft_isprint ft_toupper \
		ft_tolower ft_memalloc ft_memdel \
		ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri ft_strmap \
		ft_strmapi ft_strequ ft_strnequ \
		ft_strsub ft_strjoin ft_strtrim \
		ft_strsplit ft_itoa ft_putchar \
		ft_putstr ft_putendl ft_putnbr \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		ft_putnbr_fd ft_lstnew ft_lstdelone \
		ft_lstdel ft_lstadd ft_lstiter \
		ft_lstmap ft_lstsplit ft_wordcount \
		ft_wordfound ft_lstfold ft_swap \
		ft_strlchr ft_nbrlen get_next_line \
		exit

HEADERS = libft

define colorecho
	  @tput setaf $2
	  @echo $1
	  @tput sgr0
endef

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(call colorecho, "║ $(NAME): Packing files...          ║", 3)
	@ar rc $(NAME) $(OBJ)
	$(call colorecho, "║ $(NAME): Building library...       ║", 3)
	@ranlib $(NAME)
	$(call colorecho, "║ $(NAME): Complete!                 ║", 2)

$(OBJ_DIR):
	$(call colorecho, "║ $(NAME): Creating object folder... ║", 3)
	@mkdir $(OBJ_DIR)
	$(call colorecho, "║ $(NAME): Compiling source...       ║", 3)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAG) -I $(INC_DIR) -o $@ -c $<

clean:
	$(call colorecho, "║ $(NAME): Deleting object files...  ║", 1)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(call colorecho, "║ $(NAME): Deleting old lib...       ║", 1)
	@rm -f $(NAME)
	@rm -f get_next_line.h.gch

re: fclean all

.PHONY: clean fclean re header
