NAME = fdf
FILES =  add_fun.c addictional_funcs_validate.c changecolor.c displayer.c draw_line.c \
	ft_realloc.c gradient.c main.c menu.c rotation.c rotation_main.c validation_funsc.c validation_main.c xyziso.c

SRC = $(addprefix srs/, $(FILES))
FILESO = ${SRC:.c=.o}
FLAGS = -Wall -Werror -Wextra
MIN = -L minilibx_macos/ -lmlx
ADD = -framework OpenGL -framework AppKit 
INCL = -I ./libft
INCLM = -I ./minilibx_macos
LIBA = -L libft/ -lft

all: $(NAME)


$(NAME): $(FILESO)
	make -C ./libft/
	make -C ./minilibx_macos/
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBA) $(MIN) $(ADD)

%.o:%.c
	gcc $(FLAGS) $(INCL) -o $@ -c $<

clean:
	rm -f $(FILESO)
	make clean -C ./libft/
	make clean -C ./minilibx_macos/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all