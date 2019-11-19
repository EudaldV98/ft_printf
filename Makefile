# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 15:04:31 by jvaquer           #+#    #+#              #
#    Updated: 2019/11/19 16:00:22 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = libftprintf.a

SRC_PATH = ./src

LIB_PATH = ./libft

INC_PATH = ./inc

OBJ_PATH = ./obj

OBJLIB_PATH = ./libft

SRC_NAME =  ft_printf.c ft_printf_utils.c ft_specifier_c.c ft_specifier_d.c ft_flags.c \
            ft_flags_2.c ft_exception.c ft_specifier_mod.c ft_specifier_p.c ft_specifier_s.c \
			ft_specifier_u.c ft_specifier_x.c ft_specifier_xp.c

LIB_NAME =  ft_atoi.c ft_substr.c ft_strlcpy.c \
            ft_putchar_fd.c ft_strdup.c \
            ft_putstr_fd.c ft_strncmp.c \
            ft_strlen.c \
            ft_itoa.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@ar rc $(NAME) $(OBJ) $(OBJLIB) libft/libft.a
	@ranlib $(NAME)
	@echo "__, ___      __, __, _ _, _ ___ __,"
	@echo "|_   |       |_) |_) | |\ |  |  |_ "
	@echo "|    |       |   | \ | | \|  |  |  "
	@echo "~    ~  ~~~~ ~   ~ ~ ~ ~  ~  ~  ~  "
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"