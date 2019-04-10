/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:10:10 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 15:25:21 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_r	*clone_line(t_point *t, int h)
{
	int			i;
	t_point_r	*line;

	line = (t_point_r*)malloc(sizeof(t_point_r) * h);
	i = 0;
	while (i < h)
	{
		line[i].x = (double)t[i].x;
		line[i].y = (double)t[i].y;
		line[i].z = t[i].z;
		line[i].color = t[i].color;
		i++;
	}
	return (line);
}

t_point_r	**clone_points(t_point **points, int h, int v)
{
	t_point_r	**cloned_points;
	int			i;

	i = 0;
	cloned_points = (t_point_r**)malloc(sizeof(t_point_r) * (v + 1));
	cloned_points[v] = NULL;
	while (i < v)
	{
		cloned_points[i] = clone_line(points[i], h);
		i++;
	}
	return (cloned_points);
}

t_map_r		*clone_map(t_map *map)
{
	t_map_r	*rotated_map;

	rotated_map = (t_map_r*)malloc(sizeof(t_map_r));
	rotated_map->angle_z = 0;
	rotated_map->angle_x = 0;
	rotated_map->angle_y = 0;
	rotated_map->size_h = map->size_h;
	rotated_map->size_v = map->size_v;
	rotated_map->points = clone_points(map->points, map->size_h, map->size_v);
	return (rotated_map);
}

t_map_r		*make_map_r(t_map *map, double angle, int fd)
{
	t_map_r		*rotated_map;
	t_point_r	**p;
	int			i;
	int			j;

	rotated_map = clone_map(map);
	p = rotated_map->points;
	i = 0;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			rotate_point(&(p[i][j]), angle);
			j++;
		}
		i++;
	}
	close(fd);
	return (rotated_map);
}
