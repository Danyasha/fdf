/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:02:13 by marvin            #+#    #+#             */
/*   Updated: 2019/04/10 10:02:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (key == 3)
	{
		go_black(map2, *map);
		fill_color(t->i, t->w, 1);
	}
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
	//fill_color(t->i, t->w, 0);
	displayer(*t, map2, *kek);
	return 0;
}