###########Diretory###########
SRC_DIR 		= src/
PARSER_DIR		= src/parser/
RENDER_DIR		= src/render/
UTILS_DIR		= src/utils/

RENDER_SRCS_DIR 				= $(RENDER_DIR)
HANDLE_RENDER_SRCS_DIR			= $(RENDER_DIR)handle/
OBJECt_ren_SRCS_DIR 			= $(RENDER_DIR)objects/
VECTOR_RENDER_SRCS_DIR 			= $(RENDER_DIR)vector/
PARSING_SRCS_DIR				= $(PARSER_DIR)
FILLER_PARSE_SRCS_DIR			= $(PARSER_DIR)filler/
UTILS_PARSING_SRCS_DIR			= $(PARSER_DIR)p_utils/
ERROR_UTILS_SRCS_DIR			= $(UTILS_DIR)error_management/
BACKFONC_UTILS_SRCS_DIR 		= $(UTILS_DIR)back_fonction/
INIT_BACKFONC_UTILS_SRCS_DIR	= $(UTILS_DIR)init_free/

BUILDS_DIR			= builds
LIBFT_DIR   		= libft/
MLX_DIR				= macrolibx/
###############################

###########FILES###########
MAIN_FILES 			= miniRT.c
RENDER_FILES		= render.c render_utils_1.c render_utils_2.c color.c
DRAW_FILES			= central_draw.c
OBJECT_FILES		= sphere.c cylinder.c plane.c
HANDLE_FILES		= key1.c key2.c mouse1.c window1.c handle_utils.c
VECTOR_FILES		= vector.c vector_operations.c
PARSING_FILES		= central_verif.c
P_UTILS_FILES		= check_1.c check_2.c check_3.c
FILLER_FILES		= fill_objs.c fill_param.c
ERROR_FILES			= error_manage.c
BACK_FONCK_FILES	= back_fnct1.c back_fnct2.c back_fnct3.c back_fnct4.c back_fnct5.c ft_strtod.c
INIT_FREE_FILES		= init_majoris.c free1.c
###########################

###########SOURCES###########
MAIN_SOURCES				= $(MAIN_FILES)
RENDER_SOURCES				= $(addprefix $(RENDER_SRCS_DIR), $(RENDER_FILES))
HANDLE_SOURCES				= $(addprefix $(HANDLE_RENDER_SRCS_DIR), $(HANDLE_FILES))
OBJECT_SOURCES				= $(addprefix $(OBJECt_ren_SRCS_DIR), $(OBJECT_FILES))
VECTOR_SOURCES				= $(addprefix $(VECTOR_RENDER_SRCS_DIR), $(VECTOR_FILES))
PARSING_SOURCES 			= $(addprefix $(PARSING_SRCS_DIR), $(PARSING_FILES))
P_UTILS_SOURCES 			= $(addprefix $(UTILS_PARSING_SRCS_DIR), $(P_UTILS_FILES))
FILLER_PARSE_SRCS_SOURCE	= $(addprefix $(FILLER_PARSE_SRCS_DIR), $(FILLER_FILES))
ERROR_SOURCES				= $(addprefix $(ERROR_UTILS_SRCS_DIR), $(ERROR_FILES))
UTILS_SOURCES				= $(addprefix $(BACKFONC_UTILS_SRCS_DIR), $(BACK_FONCK_FILES))
INIT_FREE_SOURCES			= $(addprefix $(INIT_BACKFONC_UTILS_SRCS_DIR), $(INIT_FREE_FILES))

SOURCES			= $(MAIN_SOURCES) \
					$(RENDER_SOURCES) \
					$(OBJECT_SOURCES) \
					$(HANDLE_SOURCES) \
					$(VECTOR_SOURCES) \
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

