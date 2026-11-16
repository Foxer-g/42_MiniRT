
include sources.mk

########### COLOR ###########
RESET   = \e[0m
D_RED   = \e[1;38;2;187;6;6m
MAG     = \e[1;38;2;242;0;255m
Z_BLUE  = \e[1;38;2;22;184;243m
ORANGE  = \e[1;38;2;255;128;0m
#############################

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -ggdb
NAME        := miniRT

MAKEFLAGS   += --no-print-directory

BUILD_DIR   := build/
LIBFT       := libft/libft.a
MLX         := macrolibx/libmlx.so
INCLUDES    := -I ./includes -I libft/includes -I macrolibx/includes
LDFLAGS     := $(LIBFT) $(MLX) -lSDL2 -lm

OBJS        := $(patsubst %.c,$(BUILD_DIR)%.o,$(SOURCES))
DEPS        := $(OBJS:.o=.d)

all: $(NAME)

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -j -C macrolibx

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) clean -C libft
	$(MAKE) clean -C macrolibx

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
