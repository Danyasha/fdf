/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:10:05 by btorp             #+#    #+#             */
/*   Updated: 2019/04/09 17:14:32 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		get_delta(t_point start, t_point end)
{
	t_point	delta;

	delta.x = (double)abs((int) start.x - end.x);
	delta.y = (double)abs((int) start.y - end.y);
	return (delta);
}

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int 		get_color(t_gradient *t)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (t->color_cur == t->color_2)
		return (t->color_cur);
	if (t->dx > t->dy)
		percentage = percent(t->startx, t->endx, t->cur_x);
	else
		percentage = percent(t->starty, t->endy, t->cur_y);
	red = get_light((t->color_1 >> 16) & 0xFF, (t->color_2 >> 16) & 0xFF, percentage);
	green = get_light((t->color_1 >> 8) & 0xFF, (t->color_2 >> 8) & 0xFF, percentage);
	blue = get_light(t->color_1 & 0xFF, t->color_2 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
