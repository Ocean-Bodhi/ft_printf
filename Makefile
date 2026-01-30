NAME = libftprintf.a

# Directories
INC_DIR = includes/
SRC_DIR = srcs/
OBJS_DIR = objs

CC = cc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_DIR)

# Source files and object files
SRC = \
	$(SRC_DIR)ft_printf.c \
	$(SRC_DIR)ft_putchar.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJS_DIR)/%.o)

# Regla por defecto
all: $(NAME)

# crear libreria estática:
$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

# REGLA para Compilación de cada .o
# Añado los nombres (Makefile y *.h) para actualizar si cambios
# echo para ver lo que está haciendo
$(OBJS_DIR)/%.o : $(SRC_DIR)%.c Makefile $(INC_DIR)*.h
	mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: all clean fclean re

# Limpiar objetos
clean:
	rm -rf $(OBJS_DIR)

# Limpiar objetos y .a
fclean: clean
	rm -f $(NAME)

# Reconstruir todo
re: fclean all
