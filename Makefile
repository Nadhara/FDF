# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 04:13:47 by apruvost          #+#    #+#              #
#    Updated: 2018/02/09 15:47:53 by apruvost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

SRCS = 	main.c \
		line.c \
		getfile.c \
		mapcreate.c \
		draw.c \
		key_push.c \
		ft_ui.c \
		color.c

OBJS = $(SRCS:.c=.o)

LIB_PATH = libft
LIB_LINK = -L $(LIB_PATH) -lft

MLX_PATH = minilibx_macos
MLX_LINK = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

INC_DIR = fdf.h
INCS = -I ./$(INC_DIR) -I $(INC_DIR)

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@make -C minilibx_macos/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_LINK) $(MLX_LINK)
	@echo "FDF Done !"

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<


clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@echo "Objects files deleted."

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean
	@echo "$(NAME) deleted."

relib:
	@make -C libft/ re
	@make -C minilibx_macos/ re
	@echo "Libs redone."

re: fclean all

respeed:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_LINK) $(MLX_LINK)
	@echo "FDF Done !"

gorespeed: respeed
	./fdf test.fdf