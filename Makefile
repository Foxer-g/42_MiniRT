include sources.mk

NAME = miniRT
BUILD_DIR = build/
INCLUDES = includes -I libft/includes -I macrolibx/includes
OBJECTS = $(SOURCES:src/%.c=$(BUILD_DIR)%.o)
CFLAGS = -Wall -Wextra -Werror -ggdb
LDFLAGS = libft/libft.a macrolibx/libmlx.so -lSDL2
CC = cc

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

libft/libft.a:
	make -C libft

macrolibx/libmlx.so:
	make -j -C macrolibx

$(NAME): libft/libft.a macrolibx/libmlx.so $(BUILD_DIR) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	-rm -f $(OBJECTS)
	make clean -C libft
	make clean -C macrolibx

fclean: clean
	-rm -f $(NAME)
	-rm -fr $(BUILD_DIR)
	make fclean -C libft

re: fclean all

.PHONY: all re fclean clean
