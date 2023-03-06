# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 11:10:21 by kzak              #+#    #+#              #
#    Updated: 2023/03/06 22:36:57 by kzak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

CC = gcc

SRC_LIBFT = lib/ft_atoi.c \
	  lib/ft_bzero.c \
	  lib/ft_calloc.c \
	  lib/ft_isalnum.c \
	  lib/ft_isalpha.c \
	  lib/ft_isascii.c \
	  lib/ft_isdigit.c \
	  lib/ft_isprint.c \
	  lib/ft_itoa.c \
	  lib/ft_memchr.c \
	  lib/ft_memcmp.c \
	  lib/ft_memcpy.c \
	  lib/ft_memmove.c \
	  lib/ft_memset.c \
	  lib/ft_putchar_fd.c \
	  lib/ft_putendl_fd.c \
	  lib/ft_putnbr_fd.c \
	  lib/ft_putstr_fd.c \
	  lib/ft_split.c \
	  lib/ft_strchr.c \
	  lib/ft_strdup.c \
	  lib/ft_striteri.c \
	  lib/ft_strjoin.c \
	  lib/ft_strlcat.c \
	  lib/ft_strlcpy.c \
	  lib/ft_strlen.c \
	  lib/ft_strmapi.c \
	  lib/ft_strncmp.c \
	  lib/ft_strnstr.c \
	  lib/ft_strrchr.c \
	  lib/ft_strtrim.c \
	  lib/ft_substr.c \
	  lib/ft_tolower.c \
	  lib/ft_toupper.c \
	  lib/ft_lstadd_back.c \
	  lib/ft_lstadd_front.c \
	  lib/ft_lstclear.c \
	  lib/ft_lstdelone.c \
	  lib/ft_lstiter.c \
	  lib/ft_lstlast.c \
	  lib/ft_lstmap.c \
	  lib/ft_lstnew.c \
	  lib/ft_lstsize.c \
	  lib/ft_strcpy.c \
	  lib/ft_isspace.c \
	  lib/ft_atol.c \
	  lib/ft_print_str_array.c \
	  lib/ft_atol_base.c \
	  lib/ft_strreplace.c \
	  lib/ft_strspn.c \
	  lib/ft_free_char_array.c \
	  lib/ft_str_array_len.c \

SRC_PRINTF = ft_printf/ft_printf.c \
				ft_printf/ft_printf_utils.c \

SRC_GNL = gnl/get_next_line.c \
				gnl/get_next_line_utils.c \

OBJ_DIR = obj

OBJ = $(SRC_LIBFT:lib/%.c=$(OBJ_DIR)/lib/%.o) \
		$(SRC_PRINTF:ft_printf/%.c=$(OBJ_DIR)/ft_printf/%.o) \
		$(SRC_GNL:gnl/%.c=$(OBJ_DIR)/gnl/%.o) \

all: $(NAME)

clean:
	@echo "     - Removing $(NAME)..."
	@rm -rf $(OBJ_DIR)
	@echo "          libft OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "          $(NAME) deleted"

re: fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@mkdir obj/lib
	@mkdir obj/ft_printf
	@mkdir obj/gnl

$(OBJ_DIR)/lib/%.o : lib/%.c 
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/ft_printf/%.o : ft_printf/%.c 
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/gnl/%.o : gnl/%.c 
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "          $(NAME) created"
	@ranlib $(NAME)

.PHONY : all clean fclean re
