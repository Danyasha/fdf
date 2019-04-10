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

// static	void	makevoid(**void)
// {

// }

static	void	make_t_move(t_move kek)
{
	kek.x = WINDOW_HEIGHT / 2;
	kek.y = WINDOW_WIDTH / 2;
	kek.k = START_K;
}

static	void	make_t_mlx(t_mlx t)
{
	t.i = mlx_init();
	t.w = mlx_new_window(t.i, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
}

static	t_fuck_norme	make_fuck_off_norme(t_fuck_off_norme norme)
{
	z.kek = make_t_move(kek);
	z.t = make_t_mlx(z.t);
}

int		main(int argn, char **argv)
{
	int					fd;
	t_map				*map;
	void				*a[4];
	t_fuck_off_norme	z;
	t_map_r				*map2;

	fd = open(argv[1], O_RDONLY);
	if (argn != 2)
		return(exiter("usage: ./fdf filename\n"));
	if (read(fd, NULL, 0) < 0)
		return(exiter("invalid file\n"));
	if(!(map = validate_main(fd)))
		return(exiter("bad map\n"));
	else
		ft_putstr("norm map\n");
	close (fd);
	map2 = make_map_r(map, ISO_ANGLE);
	z = make_fuck_off_norme(z);
	displayer(z.t, map2, z.kek);
	a[0] = &(z.t);
	a[1] = &(z.kek);
	a[2] = map2;
	a[3] = map;
	mlx_hook(t.w, 2, 18, key_press, a);
	mlx_loop(t.i);
	return (0);
}
