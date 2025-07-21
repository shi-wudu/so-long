SRCS			=	main.c

NAME			=	so_long

OBJS			=	$(SRCS:.c=.o)

CC				=	cc

CFLAGS			=	-Imlx_linux

MLX_FLAGS		=	mlx_linux/mlx.h -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

all:		$(NAME)

%.o: %.c
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
					rm -f $(OBJS)

fclean: 	clean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re