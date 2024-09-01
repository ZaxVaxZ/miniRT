CC = cc

CCFLAGS = -Wall -Wextra -Werror -I./../../inc/

AR = ar

ARFLAGS = -rcs

FILES = ft_isprint.c ft_isalnum.c ft_calloc.c ft_atoi.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strlen.c\
		ft_strnstr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar_fd.c\
		ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_itoa.c\
		ft_split.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_memcpy.c

OBJ = $(FILES:.c=.o)

NAME = libft.a

BONUSC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSO = $(BONUSC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

bonus: all $(NAME) $(BONUSO)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSO)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(BONUSO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus