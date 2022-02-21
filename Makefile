# -*- Makefile -*-

NAME := fdf

ifdef debug
CFLAGS = -Wall -fsanitize=address -Wextra -g
else
CFLAGS := -Wall -Wextra -Werror
endif

CC := gcc

GNL :=		gnl/get_next_line.c \
			gnl/get_next_line_utils.c

SRCS :=		src/main.c \
			src/my_pixel_put.c \
			src/put_screen.c \
			src/input_handling.c \
			src/array_length.c \
			src/determine_line_length.c \
			src/free_fdf.c \
			src/events.c \
			src/open_window.c \
			src/draw_line.c \
			src/zoom.c \
			src/make_vars_compute.c \
			src/rotate.c \
			src/scale_z.c

INC := -I ./inc

LIBFT := libft/libft.a

MLX := mlx/libmlx.dylib

RED := "\033[0;31m"
GREEN := "\033[1;32m"
CYAN := "\033[1;36m"

all : $(NAME)

$(NAME) : $(SRCS) $(GNL) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(INC) -o $@ $^ 
	@echo $(CYAN)"fdf compiled [OK]"

$(LIBFT) :
	@echo $(RED)"Compiling Libft" $(GREEN)
	@$(MAKE) bonus -C libft
	@echo $(CYAN) "libft compiled [OK]"

$(MLX) :
	@echo $(RED) "Compiling MLX"
	@$(MAKE) -C mlx 
	@test -e libmlx.dylib || ln -sf mlx/libmlx.dylib libmlx.dylib
	@echo $(CYAN) "MLX compiled [OK]"

clean :
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C mlx

fclean :
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C mlx
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@echo $(GREEN) "Deleting fdf"

re : fclean all

.PHONY : all, clean, fclean, re
