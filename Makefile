LIB = -L libft/ -lmlx
mlx_test:
	gcc -I minilibx_macos/ srs/tests/minilib/main.c -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit 
iso:
	gcc -I minilibx_macos/ srs/tests/isometric/main.c -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit 
line:
	gcc -I minilibx_macos/ srs/tests/draw_line_test/main.c  srs/draw_line.c -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -g
valid:
	gcc -I minilibx_macos/ srs/tests/validation_test/main.c  libft/libft.a srs/*.c -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -g
map:
	gcc -I minilibx_macos/ srs/tests/draw_map/draw_map.c  libft/libft.a srs/*.c -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -g