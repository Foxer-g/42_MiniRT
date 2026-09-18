# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:42:42 by rboutelo          #+#    #+#              #
#    Updated: 2026/09/18 15:40:34 by ethutin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources.mk

NAME		= libft.a
INCLUDES	= ./includes
BUILD_DIR	= build/
OBJECTS		= $(SOURCES:src/%.c=$(BUILD_DIR)%.o)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g3
Q			= @

all: monolithic

monolithic: $(NAME)

hierarchical: configure
	$(Q)./waf build

configure:
	$(Q)./waf configure

$(BUILD_DIR):
	$(Q)mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o: src/%.c
	$(Q)mkdir -p $(dir $@)
	$(Q)$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(BUILD_DIR) $(OBJECTS)
	$(Q)ar rcs $(NAME) $(OBJECTS)
	$(Q)echo "\033[1;38;2;187;6;6m[\033[1;38;2;242;0;255mLIBFT\033[1;38;2;187;6;6m] \033[1;38;2;255;128;0mCompiled successfully!\033[0m"

clean:
	$(Q)rm -f $(OBJECTS)

fclean: clean
	$(Q)rm -f $(NAME)

re: fclean all

test: all
	$(Q)testament all

.PHONY: all re fclean clean hierarchical configure monolithic test
