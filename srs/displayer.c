/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:42:31 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 15:50:56 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_around(t_mlx t, t_map_r *map, t_aa a, t_move u)
{
	t_line		line;
	t_point_r	**p;
	int			i;
	int			j;

	i = a.x;
	j = a.y;
	p = map->points;
	line.x0 = (p[i][j].x * u.k + u.x);
	line.y0 = (p[i][j].y * u.k + u.y);
	line.start = p[i][j].color;
	if (i != 0)
	{
		line.x1 = (p[i - 1][j].x * u.k + u.x);
		line.y1 = (p[i - 1][j].y * u.k + u.y);
		line.end = p[i - 1][j].color;
		draw_line(&line, t.i, t.w);
	}
	if (j != 0)
	{
		line.x1 = (p[i][j - 1].x * u.k + u.x);
		line.y1 = (p[i][j - 1].y * u.k + u.y);
		line.end = p[i][j - 1].color;
		draw_line(&line, t.i, t.w);
	}
}

void	displayer(t_mlx t, t_map_r *map, t_move u)
{
	t_point_r	**p;
	int			i;
	int			j;
	t_aa		a;

	i = 0;
	p = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			a.x = i;
			a.y = j;
			display_around(t, map, a, u);
			j++;
		}
		i++;
	}
}
