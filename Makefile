NAME = so_long
CC = cc
GNL = GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c
LIBFT = libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strchr.c libft/ft_strdup.c \
		libft/ft_strjoin.c libft/ft_strlcpy.c libft/ft_strncmp.c libft/ft_split.c libft/ft_putnbr_fd.c \
		libft/ft_itoa.c
SRCDIR = mandatory/
BNSDIR = bonus/
CFILES = main.c errors.c parsing.c displaymap.c split_sl.c strlen_sl.c \
			utils.c displayactors.c gettextures.c movement.c parsing2.c destroytextures.c
BCFILES = main_bonus.c errors_bonus.c parsing_bonus.c displaymap_bonus.c split_sl_bonus.c strlen_sl_bonus.c \
			utils_bonus.c displayactors_bonus.c gettextures_bonus.c movement_bonus.c parsing2_bonus.c loophook_bonus.c loophook2_bonus.c \
			attacking_bonus.c destroytextures_bonus.c
SRCS = $(addprefix $(SRCDIR), $(CFILES)) $(GNL) $(LIBFT)
BSRCS = $(addprefix $(BNSDIR), $(BCFILES)) $(GNL) $(LIBFT)
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
OS := $(shell uname)
ifeq ($(OS),Linux)
	MLX = mlx_linux/libmlx.a
	MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	CFLAGS = -Wall -Wextra -I/usr/include -Imlx_linux -O3
	MLX_DIR = mlx_linux
else
	MLX = mlx/libmlx.a
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
	CFLAGS = -Wall -Wextra -Werror -Imlx
	MLX_DIR = mlx
endif

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

bonus: $(MLX) $(BOBJS)
	$(CC) $(BOBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean: clean
	rm -rf so_long

re: fclean all

.PHONY: all clean fclean re bonus