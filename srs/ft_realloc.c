/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:07:56 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 08:32:23 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_arraydel(t_point ***a, int size)
{
	int		i;
	t_point	**temp;

	temp = *a;
	i = 0;
	while (i != size)
	{
		free(temp[i]);
		i++;
	}
	free(*a);
	*a = NULL;
}

void			tpoint_cpy(t_point **dst, t_point *srs, int n)
{
	t_point	*temp;
	int		i;

	i = 0;
	*dst = (t_point*)malloc(sizeof(t_point) * n);
	temp = *dst;
	while (i < n)
	{
		temp[i].x = srs[i].x;
		temp[i].y = srs[i].y;
		temp[i].z = srs[i].z;
		temp[i].color = srs[i].color;
		i++;
	}
}

t_point			**ft_realloc(t_point ***a, int new_size, int h_size)
{
	t_point	**temp;
	int		i;
	t_point	**temp_a;

	temp_a = *a;
	i = 0;
	if (new_size - 1 == 1)
	{
		*a = (t_point**)malloc(2 * sizeof(t_point*));
		(*a)[1] = NULL;
		return (*a);
	}
	temp = (t_point**)malloc(sizeof(t_point*) * new_size);
	temp[new_size - 1] = NULL;
	while (temp_a[i])
	{
		tpoint_cpy(&temp[i], temp_a[i], h_size);
		i++;
	}
	ft_arraydel(a, new_size - 1);
	return (temp);
}
