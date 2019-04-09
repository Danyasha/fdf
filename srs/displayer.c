/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:42:31 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 10:30:39 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_around(t_mlx t, t_map_r *map, int i, int j, t_move u)
{
	t_line	*line;
	t_point_r **p;

	line = (t_line*)malloc(sizeof(t_line));
	p = map->points;
	line->x0 = (p[i][j].x * u.k + u.x);
	line->y0 = (p[i][j].y * u.k + u.y);
	line->start = p[i][j].color;
	if (i != 0)
	{
		line->x1 = (p[i - 1][j].x * u.k + u.x);
		line->y1 = (p[i - 1][j].y * u.k + u.y);
		line->end = p[i - 1][j].color;
		draw_line(line, t.i, t.w);
	}
	if (j != 0)
	{
		line->x1 = (p[i][j - 1].x * u.k + u.x);
		line->y1 = (p[i][j - 1].y * u.k +  u.y);
		line->end = p[i][j - 1].color;
		draw_line(line, t.i, t.w);
	}

	if (i + 1 < map->size_v)
	{
		line->x1 = (p[i + 1][j].x * u.k + u.x);
		line->y1 = (p[i + 1][j].y * u.k + u.y);
		line->end = p[i + 1][j].color;
		draw_line(line, t.i, t.w);
	}

	if (j + 1 < map->size_h)
	{
		line->x1 = (p[i][j + 1].x * u.k + u.x);
		line->y1 = (p[i][j + 1].y * u.k + u.y);
		line->end = p[i][j + 1].color;
		draw_line(line, t.i, t.w);
	}
}

void	displayer(t_mlx t, t_map_r *map, t_move u)
{
	t_point_r **p;
	int	i;
	int	j;

	i = 0;
	p = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			display_around(t, map, i, j, u);
			j++;
		}
		i++;
	}
}