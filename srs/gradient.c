/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:09:34 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 14:31:03 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

// double percent(int start, int end, int current)
// {
// 	double placement;
// 	double distance;

// 	placement = current - start;
// 	distance = end - start;
// 	return ((distance == 0) ? 1.0 : (placement / distance));
// }

// int get_light(int start, int end, double percentage)
// {
// 	return ((int)((1 - percentage) * start + percentage * end));
// }

// int get_color(int current, t_line delta)
// {
// 	int		red;
// 	int		green;
// 	int		blue;
// 	double	percentage;

// 	if (color == delta.color)
//         return (color);
// 	if (delta.x > delta.y)
//         percentage = percent(delta.start delta.x, current.x);
// 	else
//         percentage = percent(start.y, end.y, current.y);
// 	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
// 	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
// 	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
//     return ((red << 16) | (green << 8) | blue);
// }