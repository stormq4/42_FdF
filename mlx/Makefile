


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)

NAME=libmlx.dylib

INC=-I.

GREEN := "\033[1;32m"

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz

%.o: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	@rm -f $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
	@echo $(GREEN) "Deleting object files from MLX"

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN) "Deleting libmlx.dylib from MLX"
