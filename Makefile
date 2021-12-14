# -*- Makefile -*-

NAME := fdf

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS := 	src/main.c \
			src/error.c \
			src/t_pixl.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \

HEADFILES := src/fdf.h

LIBFT := libft/libft.a

MLX := mlx/libmlx.dylib

all : $(NAME)

$(NAME) : $(SRCS) $(LIBFT) $(MLX)
	$(CC) -o $@ $^ -fsanitize=address

$(LIBFT) :
	$(MAKE) bonus -C libft

$(MLX):
	$(MAKE) -C mlx && test -e libmlx.dylib || ln -sf mlx/libmlx.dylib libmlx.dylib

clean :
	$(MAKE) clean -C libft

fclean : 
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
