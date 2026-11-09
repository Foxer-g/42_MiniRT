<<<<<<< HEAD
###########Diretory###########
SRC_DIR 		= src/
UTILS_DIR		= src/utils/
=======
SRC_DIR = src/
RENDER_SRCS_DIR = $(SRC_DIR)render/
VECTOR_SRCS_DIR = $(RENDER_SRCS_DIR)vector/
OBJECT_SRCS_DIR = $(RENDER_SRCS_DIR)objects/
PARSING_SRCS_DIR = $(SRC_DIR)parser/
>>>>>>> render

RENDER_SRCS_DIR 		= $(SRC_DIR)render/
PARSING_SRCS_DIR		= $(SRC_DIR)parser/
ERROR_UTILS_SRCS_DIR	= $(UTILS_DIR)error_management/
BACKFONC_UTILS_SRCS_DIR = $(UTILS_DIR)back_fonction/

<<<<<<< HEAD
BUILDS_DIR				= builds
LIBFT_DIR   			= libft/
MLX_DIR					= macrolibx/
###############################

###########FILES###########
MAIN_FILES 			= miniRT.c
RENDER_FILES		= render.c
PARSING_FILES		= central_verif.c
ERROR_FILES			= error_manage1.c
BACK_FONCK_FILES	= back_fnct1.c init.c free.c
###########################

###########SOURCES###########
MAIN_SOURCES	= $(MAIN_FILES)
RENDER_SOURCES	= $(addprefix $(RENDER_SRCS_DIR), $(RENDER_FILES))
=======
RENDER_FILES = render.c utils.c color.c
VECTOR_FILES = vector.c vector_operations.c
OBJECT_FILES = sphere.c cylinder.c plane.c
PARSING_FILES = 

RENDER_SOURCES = $(addprefix $(RENDER_SRCS_DIR), $(RENDER_FILES))
VECTOR_SOURCES = $(addprefix $(VECTOR_SRCS_DIR), $(VECTOR_FILES))
OBJECT_SOURCES = $(addprefix $(OBJECT_SRCS_DIR), $(OBJECT_FILES))
>>>>>>> render
PARSING_SOURCES = $(addprefix $(PARSING_SRCS_DIR), $(PARSING_FILES))
ERROR_SOURCES	= $(addprefix $(ERROR_UTILS_SRCS_DIR), $(ERROR_FILES))
UTILS_SOURCES	= $(addprefix $(BACKFONC_UTILS_SRCS_DIR), $(BACK_FONCK_FILES))

SOURCES			= $(MAIN_SOURCES) \
					$(RENDER_SOURCES) \
					$(PARSING_SOURCES) \
					$(ERROR_SOURCES) \
					$(UTILS_SOURCES)
#############################

###########INCLUDE###########
LIBFT			= $(LIBFT_DIR)libft.a
MLX				= $(MLX_DIR)libmlx.so
LIBFT_INCLUDE	= $(LIBFT_DIR)includes/
MLX_INCLUDE		= $(MLX_DIR)includes/

#INCLUDES		= -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)
INCLUDES		= -Iincludes -I$(LIBFT_INCLUDE) -I$(MLX_INCLUDE)

#############################

<<<<<<< HEAD
=======
SOURCES = $(MAIN_SOURCES) $(RENDER_SOURCES) $(PARSING_SOURCES) $(OBJECT_SOURCES) $(VECTOR_SOURCES)
>>>>>>> render
