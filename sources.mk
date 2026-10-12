###########COLOR########### //check end
RESET		= \e[0m
D_RED		= \e[1;38;2;187;6;6m
MAG			= \e[1;38;2;242;0;255m
Z_BLUE		= \e[1;38;2;22;184;243m
ORANGE		= \e[1;38;2;255;128;0m
###########################

###########Diretory###########
SRC_DIR 		= src/
UTILS_DIR		= src/utils/


RENDER_SRCS_DIR 				= $(SRC_DIR)render/
PARSING_SRCS_DIR				= $(SRC_DIR)parser/
FILLER_PARSE_SRCS_DIR			= $(SRC_DIR)parser/filler/
UTILS_PARSING_SRCS_DIR			= $(SRC_DIR)parser/p_utils/
ERROR_UTILS_SRCS_DIR			= $(UTILS_DIR)error_management/
BACKFONC_UTILS_SRCS_DIR 		= $(UTILS_DIR)back_fonction/
INIT_BACKFONC_UTILS_SRCS_DIR	= $(UTILS_DIR)init_free/

BUILDS_DIR				= builds
LIBFT_DIR   			= libft/
MLX_DIR					= macrolibx/
###############################

###########FILES###########
MAIN_FILES 			= miniRT.c
RENDER_FILES		= render.c
PARSING_FILES		= central_verif.c
P_UTILS_FILES		= check_1.c check_2.c check_3.c check_4.c
FILLER_FILES		= filler.c filler_extend.c
ERROR_FILES			= error_manage.c
BACK_FONCK_FILES	= back_fnct1.c back_fnct2.c back_fnct3.c ft_strtod.c
INIT_FREE_FILES		= init1.c init2.c init3.c free1.c free2.c
###########################

###########SOURCES###########
MAIN_SOURCES				= $(MAIN_FILES)
RENDER_SOURCES				= $(addprefix $(RENDER_SRCS_DIR), $(RENDER_FILES))
PARSING_SOURCES 			= $(addprefix $(PARSING_SRCS_DIR), $(PARSING_FILES))
P_UTILS_SOURCES 			= $(addprefix $(UTILS_PARSING_SRCS_DIR), $(P_UTILS_FILES))
FILLER_PARSE_SRCS_SOURCE	= $(addprefix $(FILLER_PARSE_SRCS_DIR), $(FILLER_FILES))
ERROR_SOURCES				= $(addprefix $(ERROR_UTILS_SRCS_DIR), $(ERROR_FILES))
UTILS_SOURCES				= $(addprefix $(BACKFONC_UTILS_SRCS_DIR), $(BACK_FONCK_FILES))
INIT_FREE_SOURCES			= $(addprefix $(INIT_BACKFONC_UTILS_SRCS_DIR), $(INIT_FREE_FILES))

SOURCES			= $(MAIN_SOURCES) \
					$(RENDER_SOURCES) \
					$(PARSING_SOURCES) \
					$(P_UTILS_SOURCES) \
					$(FILLER_PARSE_SRCS_SOURCE) \
					$(ERROR_SOURCES) \
					$(UTILS_SOURCES) \
					$(INIT_FREE_SOURCES)
#############################

###########INCLUDE###########
LIBFT			= $(LIBFT_DIR)libft.a
MLX				= $(MLX_DIR)libmlx.so
LIBFT_INCLUDE	= $(LIBFT_DIR)includes/
MLX_INCLUDE		= $(MLX_DIR)includes/

INCLUDES		= -Iincludes -I$(LIBFT_INCLUDE) -I$(MLX_INCLUDE)
#############################

