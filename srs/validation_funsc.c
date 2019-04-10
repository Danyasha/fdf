/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_funsc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:58:39 by marvin            #+#    #+#             */
/*   Updated: 2019/04/10 09:58:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*makemap()
{
	t_map *map;
	
	map = (t_map*)malloc(sizeof(t_map));
	map->size_h = -1;
	map->size_v = 1;
	map->points = NULL;
	return (map);
}

int		check_size_h(char	**splited, t_map *map)
{
	int	len;

	if (splited == NULL)
		return (0);
	len = array_len(splited);
	if (map->size_h == -1)
	{
		map->size_h = len;
		return (1);
	}
	if (map->size_h == len)
		return (1);
	return (0);
}

int		check_point(char *str)
{
	char	**splited;

	splited = ft_strsplit(str, ',');
	if (array_len(splited) != 2 && splited)
		return (free_strstr(&splited));
	if (!splited)
	{
		if (!doesitint(str))
			return (0);
	}
	else
	{
		if (!doesitint(splited[0]))
			return (free_strstr(&splited));
		if (!does_it_16int(splited[1]))
			return (free_strstr(&splited));
	}
	return (1);
}
