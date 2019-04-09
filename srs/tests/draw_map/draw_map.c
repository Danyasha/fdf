#include "../tests.h"
static	int		exiter(char *s)
{
	ft_putstr(s);
	return (0);
}

void	fill(void *init, void *w, int c)
{
	for(int i = 0; i<= WINDOW_HEIGHT; i++)
	{
		for (int j = 0; j<= WINDOW_WIDTH; j++)
		{
			mlx_pixel_put(init, w, i, j, c);
		}
	}
}
int	key_press(int key, void *p)
{
	t_mlx *t;
	void 	**p2;

	p2 = (void**)p;
	t = (t_mlx*)p2[0];
	t_map_r *map2 = p2[2];
	t_move *kek = p2[1];
	t_map *map = p2[3];
	printf("key = %i\n", key);
	if (key == 53)
		exit(0);
	if (key == 18)
		x_os(map2, PLUS_ANGLE, *map);
	if (key == 19)
		x_os(map2, -PLUS_ANGLE, *map);
	if (key == 12)
		y_os(map2, PLUS_ANGLE, *map);
	if (key == 13)
		y_os(map2, -PLUS_ANGLE, *map);
	if (key == 0)
		z_os(map2, PLUS_ANGLE, *map);
	if (key == 1)
		z_os(map2, -PLUS_ANGLE, *map);
	if (key == 34)
		iso(map2, *map);
	if (key == 8)
		change_color(map2, *map);
	mlx_clear_window(t->i, t->w);	
	if (key == 126)
		kek->y -= DISTANCE;
	if (key == 125)
		kek->y += DISTANCE;
	if (key == 124)
		kek->x += DISTANCE;
	if (key == 123)
		kek->x -= DISTANCE;
	if (key == 24 && kek->k < 150)
		kek->k += SPEED;
	if (key == 27 && kek->k > 1)
		kek->k -= SPEED;
	if (key == 30)
		plus_z(map2, *map);
	if (key == 33)
		minus_z(map2, *map);
	displayer(*t, map2, *kek);
	return 0;
}
int		main(int argn, char **argv)
{
	int		fd;
	t_map	*map;
	float	k;

	fd = open(argv[1], O_RDONLY);
	if (argn != 2)
		return(exiter("usage: ./fdf filename\n"));
	if (read(fd, NULL, 0) < 0)
		return(exiter("invalid file\n"));
	if(!(map = validate_main(fd)))
		return(exiter("bad map\n"));
	else
		ft_putstr("norm map\n");
	void	*s[4];
	t_mlx t;
	t.i = mlx_init();
	t.w = mlx_new_window(t.i, 1000, 1000, "TI PIDOR");

	k = 15;
	t_map_r *map2;
	map2 = make_map_r(map, ISO_ANGLE);
	z_os(map2, PLUS_ANGLE, *map);
	x_os(map2, PLUS_ANGLE, *map);
	y_os(map2, PLUS_ANGLE, *map);
	t_move kek;
	kek.x = 500;
	kek.y = 200;
	kek.k = START_K;
	//fill(t.i, t.w, 0xADAAFF);
	displayer(t, map2, kek);
	void *a[4];

	a[0] = &t;
	a[1] = &kek;
	a[2] = map2;
	a[3] = map;

	mlx_hook(t.w, 2, 18, key_press, a);
	mlx_loop(t.i);
	close (fd);
	return (0);
}
