/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:32:57 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 17:25:54 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef	struct	s_brezen
{
	int		signA;
	int		singB;
	double	a;
	double	deltaerror;
	int		y;
	int		diry;
}				t_brezen;

int ft_max (int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	make_t_draw(t_line t, t_draw *d)
{
	d->iX1 = round(t.x0);
	d->iY1 = round(t.y0);
	d->iX2 = round(t.x1);
	d->iY2 = round(t.y1);
	d->deltaX = abs(d->iX1 - d->iX2);
	d->deltaY = abs(d->iY1 - d->iY2);
	d->length = ft_max(d->deltaX, d->deltaY);
	d->dX = (t.x1 - t.x0) / (double)d->length;
	d->dY = (t.y1 - t.y0) / (double)d->length;
	d->x = t.x0;
	d->y = t.y0;
}

void line_dda(t_line line, void *init, void *window)
{
	t_draw	d;
	int		color;

	color = line.start;
	make_t_draw(line, &d);
	if (d.length == 0)
	{
		mlx_pixel_put(init, window, d.iX1, d.iY1, line.start);
		return;
	}
	d.length++;
	while (d.length--)
	{
		d.x += d.dX;
		d.y += d.dY;
		// if (d.x < 0 || d.y < 0)
		// 	continue ;
		mlx_pixel_put(init, window,  round(d.x), round(d.y), line.start);
	}
}

void draw_line(t_line *line, void *init, void *window)
{
	line_dda(*line, init, window);
	return ;
}
	// int i, L, xstart, ystart, xend, yend;
	// double dX, dY, x[1000], y[1000];
// 	xstart = round(line->x0);
// 	ystart = round(line->y0);
// 	xend = round(line->x1);
// 	yend = round(line->y1);
// 	L = ft_max(abs(xend-xstart), abs(yend-ystart));
// 	dX = (line->x1-line->x0) / L;
// 	dY = (line->y1-line->y0) / L;
// 	i = 0;
// 	x[i] = line->x0;
// 	y[i] = line->y0;
// 	i++;
// 	while (i < L)
// 	{
// 		x[i] = x[i-1] + dX;
// 		y[i] = y[i-1] + dY;
// 		i++;
// 	}
// 	x[i] = line->x1;
// 	y[i] = line->y1;
// 	i = 0;
// 	while (i <= L)
// 	{
// 		mlx_pixel_put(init, window, round(x[i]), round(y[i]), DEFAULT_COLOR); /* Draws a point. */
// 		i++;
// 	}
// }