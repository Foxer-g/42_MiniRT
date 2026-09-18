# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/18 14:10:09 by ethutin-          #+#    #+#              #
#    Updated: 2026/09/18 14:33:37 by toespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources.mk

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g

NAME        := miniRT
BUILDS_DIR  := builds

MAKEFLAGS 	+= --no-print-directory //Remove this to view the directories

LIBFT_DIR	:= libft/
LIBFT_INCL	:= $(LIBFT_DIR)includes/
MLX_DIR		:= macrolibx/

LIBFT		:= $(LIBFT_DIR)libft.a
MLX         := $(MLX_DIR)libmlx.so

INCLUDES    := -Iincludes -I$(LIBFT_INCL) -I$(MLX_DIR)
LIBS        := $(LIBFT) $(MLX)

Q			:= @

OBJS        := $(patsubst %.c,$(BUILDS_DIR)/%.o,$(SOURCES))
DEPS        := $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	$(Q)echo "\033[1;38;2;187;6;6m[\033[1;38;2;242;0;255mminiRT\033[1;38;2;187;6;6m] \033[1;38;2;255;128;0mCompiled successfully!\033[0m"

$(LIBFT):
	$(Q)$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(Q)$(MAKE) -C $(MLX_DIR)

$(BUILDS_DIR)/%.o: %.c
	$(Q)mkdir -p $(dir $@)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	$(Q)echo "\033[1;38;2;255;128;0m[CLEAN]\033[0m"
	$(Q)rm -rf $(BUILDS_DIR)
	$(Q)$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(Q)echo "\033[1;38;2;255;128;0m[FCLEAN]\033[0m"
	$(Q)$(MAKE) -C $(LIBFT_DIR) fclean
	$(Q)$(MAKE) -C $(MLX_DIR) fclean
	$(Q)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
