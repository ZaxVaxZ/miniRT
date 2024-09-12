CC = cc
CFLAGS = -Iinc -Wall -Wextra -Werror
NAME = miniRT

LIBFT_DIR = ./lib/Libft/
LIBFT_SRC = ft_strlen.c ft_atoi.c
SRCS += $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))

PRNTF_DIR = ./lib/Printf/
PRNTF_SRC = ft_extra_utils.c ft_printaddr.c ft_printhex.c ft_printuint.c ft_handlestr.c\
			ft_printchar.c ft_printint.c ft_mods_utils.c ft_printf.c ft_printstr.c
SRCS += $(addprefix $(PRNTF_DIR), $(PRNTF_SRC))

MATH_DIR = ./lib/Math/
MATH_SRC = matrix.c ray.c vector.c
SRCS += $(addprefix $(MATH_DIR), $(MATH_SRC))

SRC_DIR = ./src/
CFILES = miniRT.c
SRCS += $(addprefix $(SRC_DIR), $(CFILES))

OBJS = $(SRCS:.c=.o)
OS := $(shell uname)
ifeq ($(OS),Linux)
	MLX_DIR = lib/mlx_linux
	MLX = mlx_linux/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
	CFLAGS += -I/usr/include -I$(MLX_DIR) -O3
else
	MLX_DIR = lib/mlx_mac
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
	CFLAGS += -I$(MLX_DIR)
endif

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "Program Compilation Complete!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@make -s -C $(MLX_DIR)
	@echo "MLX Compilation Complete!"

clean:
	@make clean -s -C $(MLX_DIR)
	@rm -rf $(OBJS)
	@echo "Cleaning Complete!"

fclean: clean
	@rm -rf $(NAME)
	@echo "FCleaning Complete!"

re: fclean all

.PHONY: all clean fclean re bonus