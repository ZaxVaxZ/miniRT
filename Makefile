CC = cc
CFLAGS = -Iinc -Wall -Wextra -Werror -fsanitize=address,undefined -g3
NAME = miniRT
BONUS_NAME = miniRT_bonus

LIBFT_DIR = ./lib/Libft/
LIBFT_SRC = ft_strlen.c ft_atoi.c ft_strncmp.c
SRCS += $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
BONUS_SRCS += $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))

GNL_DIR = ./lib/get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c
SRCS += $(addprefix $(GNL_DIR), $(GNL_SRC))
BONUS_SRCS += $(addprefix $(GNL_DIR), $(GNL_SRC))

MATH_DIR = ./lib/Math/
MATH_SRC = math_utils.c intersect_utils.c matrix.c vector.c intersect.c
SRCS += $(addprefix $(MATH_DIR), $(MATH_SRC))

MATH_BONUS_DIR = ./lib/Math_Bonus/
MATH_SRC = math_utils.c intersect_utils.c matrix.c vector.c intersect.c
BONUS_SRCS += $(addprefix $(MATH_BONUS_DIR), $(MATH_SRC))

TMP_DIR = ./tmp/
TMP_SRC = render_extras.c
SRCS += $(addprefix $(TMP_DIR), $(TMP_SRC))
BONUS_SRCS += $(addprefix $(TMP_DIR), $(TMP_SRC))

SRC_DIR = ./src/
CFILES = parse_utils.c parse_objs.c parser.c miniRT.c render.c hooks.c free.c scene.c read_values.c
SRCS += $(addprefix $(SRC_DIR), $(CFILES))

BONUS_SRC_DIR = ./src_bonus/
CFILES = parse_utils.c parse_objs.c parser.c miniRT.c render.c hooks.c free.c scene.c read_values.c
BONUS_SRCS += $(addprefix $(BONUS_SRC_DIR), $(CFILES))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
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

bonus: $(BONUS_NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "Program Compilation Complete!"

$(BONUS_NAME): $(MLX) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(CFLAGS) $(MLX_FLAGS) -o $(BONUS_NAME)
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