/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changecolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:48:08 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 17:33:18 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_map_r *map, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
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
				r[i][j].color = 0x14D9C0;
			j++;
		}
		i++;
	}
}

void	plus_z(t_map_r *map, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
	t_point		**g;

	g = a.points;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			if (g[i][j].z > 0)
			{
				r[i][j].z = r[i][j].z + 1;
				printf("here\n");
			}
			j++;
		}
		i++;
	}
}

void	minus_z(t_map_r *map, t_map a)
{
	t_point_r	**r;
	int			i;
	int			j;
	double		temp;
	t_point		**g;

	g = a.points;
	i = 0;
	r = map->points;
	while (i < map->size_v)
	{
		j = 0;
		while (j < map->size_h)
		{
			if (g[i][j].z > 0)
				r[i][j].z = r[i][j].z - 1;
			j++;
		}
		i++;
	}
}