CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME = fdf
SRCS = fdf.c ft_error.c read_map.c check_argument.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): libft $(OBJS)
	$(CC) -o $@ $(OBJS) $(MLX) $(LIBFT)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft