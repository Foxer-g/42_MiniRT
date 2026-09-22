# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/18 14:10:09 by ethutin-          #+#    #+#              #
#    Updated: 2026/09/22 15:55:33 by ethutin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources.mk

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g

NAME        := miniRT

MAKEFLAGS   += --no-print-directory #Remove this to view the directories

LIBS        := $(LIBFT) $(MLX) -lSDL2

Q           := @

OBJS        := $(patsubst %.c,$(BUILDS_DIR)/%.o,$(SOURCES))
DEPS        := $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	$(Q)echo "$(D_RED)[$(MAG)miniRT$(D_RED)] $(ORANGE)Compiled successfully!$(RESET)"

$(LIBFT):
	$(Q)$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(Q)$(MAKE) -C $(MLX_DIR)

$(BUILDS_DIR)/%.o: %.c
	$(Q)mkdir -p $(dir $@)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	$(Q)echo "$(ORANGE)[CLEAN]$(RESET)"
	$(Q)rm -rf $(BUILDS_DIR)
	$(Q)$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(Q)echo "$(ORANGE)[FCLEAN]$(RESET)"
	$(Q)$(MAKE) -C $(LIBFT_DIR) fclean
	$(Q)$(MAKE) -C $(MLX_DIR) fclean
	$(Q)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
