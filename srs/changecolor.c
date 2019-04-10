/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changecolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:48:08 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 15:47:19 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	get_c(int i)
{
	if (i == 0)
		return (0x14D9C0);
	if (i == 1)
		return (0x066FF9);
	if (i == 2)
		return (0xD41A2C);
	if (i == 3)
		return (0xF1EB40);
	if (i == 4)
		return (0x286A20);
	if (i == 5)
		return (0x5CDA1D);
	if (i == 6)
		return (0x8019CF);
	if (i == 7)
		return (0xEF3692);
	if (i < 0)
		return (0xF876E7);
	return (0x58EEF3);
}

void		anal(void *init, void *w, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WINDOW_HEIGHT)
	{
		j = 0;
		while (j <= WINDOW_WIDTH)
		{
			mlx_pixel_put(init, w, i, j, color);
			j++;
		}
		i++;
	}
}

void		fill_color(void *init, void *w, int i)
{
	static	int	l;
	int			color;

	if (i)
	{
		l++;
	}
	if (l == 0)
		color = 0xFFFFFF;
	if (l == 1)
		color = 0xECAA5B;
	if (l == 2)
		color = 0xB5CEAC;
	color = 0xFAF7FA;
	anal(init, w, color);
	if (l == 3)
		l = 0;
}

int			go_black(t_map_r *map, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	t_point		**g;

	g = a.points;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			if (g[i][j].z == 0)
				r[i][j].color = 0x626560;
			else
				r[i][j].color = 0x3B3C3A;
			j++;
		}
		i++;
	}
	return (1);
}

void		change_color(t_map_r *map, t_map a)
{
	static	int	k;
	t_point_r	**r;
	int			i;
	int			j;
	t_point		**g;

	g = a.points;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			if (g[i][j].z == 0)
				r[i][j].color = get_c(-1);
			else
				r[i][j].color = get_c(abs(((k + g[i][j].z) % 8)));
			j++;
		}
		i++;
	}
	k++;
	if (k == 8)
		k = 0;
}
