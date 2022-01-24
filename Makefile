# -*- Makefile -*-

NAME := fdf

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS :=		gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
		 	src/main.c \
			src/my_pixel_put.c \
			src/print_test.c \
			src/input_handling.c \
			src/array_length.c

HEADFILES := src/fdf.h

LIBFT := libft/libft.a

MLX := mlx/libmlx.dylib

all : $(NAME)

$(NAME) : $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^  
# -g -fsanitize=address 
#remove sanitize!!

$(LIBFT) :
	$(MAKE) bonus -C libft

$(MLX) :
	$(MAKE) -C mlx && test -e libmlx.dylib || ln -sf mlx/libmlx.dylib libmlx.dylib

clean :
	$(MAKE) clean -C libft

fclean : 
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
