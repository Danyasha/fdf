/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:22:13 by btorp             #+#    #+#             */
/*   Updated: 2019/04/03 21:03:38 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		exiter(char *s)
{
	ft_putstr(s);
	return (0);
}

int		main(int argn, char **argv)
{
	int		fd;
	t_map	*map;

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
	t.w = mlx_new_window(t.i, WINDOW_WIDTH, WINDOW_HEIGHT, "TI PIDOR");
	t_map_r *map2;
	map2 = make_map_r(map, ISO_ANGLE);
	t_move kek;
	kek.x = 500;
	kek.y = 200;
	kek.k = 15;
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
