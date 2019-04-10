/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:34:41 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 08:42:24 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		check_line(char	**splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (!check_point(splited[i]))
			return (0);
		i++;
	}
	return (1);
}

static	void	fill_point(t_point *point, int z, int color, int x, int y)
{
	point->z = z;
	point->color = color;
	point->x = x;
	point->y = y;
}

static	void	make_point(t_point	*point, char *str, int x, int y)
{
	char	**splited;

	splited = ft_strsplit(str, ',');
	if (splited)
		fill_point(point, ft_atoi(splited[0]), ft_atoi16(splited[1]), x, y);
	else
		fill_point(point, ft_atoi(str), DEFAULT_COLOR, x, y);
	free_strstr(&splited);
}

static	void	make_line(t_point ***points, char **splited, int v_size, int h_size)
{
	int	i;
	int	j;

	if (v_size == 1)
		j = 0;
	else
		j = v_size - 1;
	*points = ft_realloc(points, v_size + 1, h_size);
	(*points)[j] = (t_point*)malloc(sizeof(t_point) * h_size);
	i = 0;
	while (i < h_size)
	{
		make_point(&((*points)[j][i]), splited[i], i, j);
		i++;
	}
}

t_map			*validate_main(int fd)
{
	t_map	*map;
	char	*gnl_str;
	char	**split_str;

	split_str = NULL;
	map = makemap();
	while(get_next_line(fd, &gnl_str))
	{
		split_str = ft_strsplit(gnl_str, ' ');
		if (!check_size_h(split_str, map))
			return (exiter_validate(&map, &gnl_str, &split_str));
		if (!check_line(split_str))
			return (exiter_validate(&map, &gnl_str, &split_str));
		make_line(&(map->points), split_str,map->size_v, map->size_h);
		map->size_v = map->size_v + 1;
	}
	map->size_v = map->size_v - 1;
	return (map);
}
