CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fdf
SRCS = fdf.c ft_error.c read_map.c check_argument.c ft_count_word.c ft_free_ptr.c draw.c set_map.c dda.c rotate.c ft_operator.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft
MLX_DIR = ./minilibx/
MLX = $(MLX_DIR)libmlx.a
INCLUDE = -I$(MLX_DIR)
LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME): libft $(OBJS) $(MLX) fdf.h
	$(CC) -o $@ $(OBJS) $(INCLUDE) $(LIB) $(LIBFT)

$(MLX) :
	make -C $(MLX_DIR)

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