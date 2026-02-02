NAME = libftprintf.a

# Directories
INC_DIR 	= includes
SRC_DIR 	= srcs
OBJS_DIR 	= objs
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_DIR) -I $(LIBFT_DIR)

# Source files and object files
SRC = \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_putchar.c \
	$(SRC_DIR)/ft_putnbr.c \
	$(SRC_DIR)/ft_putstr.c \
	$(SRC_DIR)/ft_putptr.c \
	$(SRC_DIR)/ft_puthex.c \
	$(SRC_DIR)/ft_putunsg.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)

# Regla por defecto
all: $(NAME)

# crear libreria estática:
$(NAME) : $(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "*** ft_printf compiled! ***"

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# REGLA para Compilación de cada .o
# Añado los nombres (Makefile y *.h) para actualizar si cambios
$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c Makefile $(INC_DIR)/*.h
	mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: all clean fclean re

# Limpiar objetos
clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

# Limpiar objetos y .a
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
# Reconstruir todo
re: fclean all
