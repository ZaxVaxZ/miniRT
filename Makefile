CC = cc
CFLAGS = -Iinc #-Wall -Wextra -Werror
NAME = miniRT
LIBFT_DIR = ./lib/Libft/
LIBFT_SRC = ft_strlen.c ft_atoi.c
SRCS += $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
PRNTF_DIR = ./lib/Printf/
PRNTF_SRC = ft_extra_utils.c ft_printaddr.c ft_printhex.c ft_printuint.c ft_handlestr.c\
			ft_printchar.c ft_printint.c ft_mods_utils.c ft_printf.c ft_printstr.c
SRCS += $(addprefix $(PRNTF_DIR), $(PRNTF_SRC))
SRC_DIR = ./src/
CFILES = main.c
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
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus