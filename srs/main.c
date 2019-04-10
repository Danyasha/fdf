/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:22:13 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 15:30:43 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int					exiter(char *s, int fd)
{
	ft_putstr(s);
	close(fd);
	return (0);
}

static	t_move				make_t_move(void)
{
	t_move	kek;

	kek.x = WINDOW_HEIGHT / 2;
	kek.y = WINDOW_WIDTH / 2;
	kek.k = START_K;
	return (kek);
}

static	t_mlx				make_t_mlx(void)
{
	t_mlx	t;

	t.i = mlx_init();
	t.w = mlx_new_window(t.i, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	return (t);
}

static	t_fuck_off_norme	make_fuck_off_norme(void)
{
	t_fuck_off_norme	norme;

	norme.kek = make_t_move();
	norme.t = make_t_mlx();
	return (norme);
}

int							main(int argn, char **argv)
{
	int					fd;
	t_map				*map;
	void				*a[4];
	t_fuck_off_norme	z;
	t_map_r				*map2;

	fd = open(argv[1], O_RDONLY);
	if (argn != 2)
		return (exiter("usage: ./fdf filename\n", fd));
	if (read(fd, NULL, 0) < 0)
		return (exiter("invalid file\n", fd));
	if (!(map = validate_main(fd)))
		return (exiter("bad map\n", fd));
	map2 = make_map_r(map, ISO_ANGLE, fd);
	z = make_fuck_off_norme();
	displayer(z.t, map2, z.kek);
	a[0] = &(z.t);
	a[2] = map2;
	a[1] = &(z.kek);
	a[3] = map;
	mlx_hook(z.t.w, 2, 18, key_press, a);
	mlx_loop(z.t.i);
	return (0);
}
