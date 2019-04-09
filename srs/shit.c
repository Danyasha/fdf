/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:42:35 by btorp             #+#    #+#             */
/*   Updated: 2019/04/09 20:51:21 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_os(t_map_r *map, double angle, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
	t_point		**g;

	g = a.points;
	map->angle_x += angle;
	temp = map->angle_x;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			// r[i][j].y = g[i][j].y;
			// r[i][j].x = g[i][j].x;
			// r[i][j].z = g[i][j].z;
			r[i][j].y = (g[i][j].y * cos(temp) + g[i][j].z * sin(temp));
			r[i][j].z = -g[i][j].y * sin(temp) + g[i][j].z * cos(temp);
			j++;
		}
		i++;
	}
}

void	y_os(t_map_r *map, double angle, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
	t_point		**g;

	g = a.points;
	map->angle_y += angle;
	temp = map->angle_y;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			// r[i][j].y = g[i][j].y;
			// r[i][j].x = g[i][j].x;
			// r[i][j].z = g[i][j].z;
			r[i][j].x = g[i][j].x * cos(temp) + g[i][j].z * sin(temp);
			r[i][j].z = -g[i][j].x * sin(temp) + g[i][j].z * cos(temp);
			j++;
		}
		i++;
	}
}

void	z_os(t_map_r *map, double angle, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
	t_point		**g;

	g = a.points;
	map->angle_z += angle;
	temp = map->angle_z;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			r[i][j].x = g[i][j].x * cos(temp) - g[i][j].y * sin(temp);
			r[i][j].y = -g[i][j].x * sin(temp) + g[i][j].y * cos(temp);
			//r[i][j].y = g[i][j].y * cos(temp) + g[i][j].z * sin(temp);
			//r[i][j].z = -g[i][j].y * sin(temp) + g[i][j].z * cos(temp);
			r[i][j].x = g[i][j].x * cos(temp) + g[i][j].z * sin(temp);
			// r[i][j].z = -g[i][j].x * sin(temp) + g[i][j].z * cos(temp);
			j++;
		}
		i++;
	}
}

void	iso(t_map_r *map, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
	t_point		**g;

	g = a.points;
	map->angle_z = ISO_ANGLE;
	map->angle_x = ISO_ANGLE;
	map->angle_y = ISO_ANGLE;
	temp = map->angle_z;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			r[i][j].x = (double)g[i][j].x;
			r[i][j].y = (double)g[i][j].y;
			goiso(&r[i][j].x, &r[i][j].y, g[i][j].z, ISO_ANGLE);
			j++;
		}
		i++;
	}
}