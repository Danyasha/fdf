/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:02:13 by marvin            #+#    #+#             */
/*   Updated: 2019/04/10 15:30:01 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		isxyiso(int key)
{
	if (key == 18 || key == 19 || key == 12)
		return (1);
	if (key == 13 || key == 0 || key == 1)
		return (1);
	if (key == 34)
		return (1);
	return (0);
}

static	int		is_move(int key)
{
	if (key == 126 || key == 125 || key == 123)
		return (1);
	if (key == 24 || key == 124 || key == 27)
		return (1);
	return (0);
}

static	void	make_move(int key, t_move *kek)
{
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
}

static	void	xyrotate(t_map_r *map2, t_map *map, int key)
{
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
}

int				key_press(int key, void *p)
{
	t_mlx	*t;
	void	**p2;
	t_map_r	*map2;
	t_move	*kek;
	t_map	*map;

	p2 = (void**)p;
	map2 = p2[2];
	kek = p2[1];
	map = p2[3];
	t = (t_mlx*)p2[0];
	if (key == 53)
		exit(0);
	if (isxyiso(key))
		xyrotate(map2, map, key);
	else if (key == 8)
		change_color(map2, *map);
	mlx_clear_window(t->i, t->w);
	if (key == 3 && go_black(map2, *map))
		fill_color(t->i, t->w, 1);
	if (is_move(key))
		make_move(key, kek);
	displayer(*t, map2, *kek);
	return (1);
}
