/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:32:57 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 15:48:07 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		make_t_draw(t_line t, t_draw *d)
{
	d->ix1 = round(t.x0);
	d->iy1 = round(t.y0);
	d->ix2 = round(t.x1);
	d->iy2 = round(t.y1);
	d->deltax = abs(d->ix1 - d->ix2);
	d->deltay = abs(d->iy1 - d->iy2);
	d->length = ft_max(d->deltax, d->deltay);
	d->dx = (t.x1 - t.x0) / (double)d->length;
	d->dy = (t.y1 - t.y0) / (double)d->length;
	d->x = t.x0;
	d->y = t.y0;
}

t_gradient	make_gradient(t_gradient *t, t_line l)
{
	t->dy = (double)abs((int)(l.x0 - l.x1));
	t->dy = (double)abs((int)(l.y0 - l.y1));
	t->startx = l.x0;
	t->starty = l.y0;
	t->endx = l.x1;
	t->cur_x = l.x0;
	t->cur_y = l.y0;
	t->color_1 = l.start;
	t->color_2 = l.end;
	t->color_cur = l.start;
	t->endy = l.y1;
	return (*t);
}

void		line_dda(t_line line, void *init, void *window)
{
	t_draw		d;
	t_gradient	g;

	make_t_draw(line, &d);
	g = make_gradient(&g, line);
	if (d.length == 0)
	{
		mlx_pixel_put(init, window, d.ix1, d.iy1, line.start);
		return ;
	}
	while (d.length--)
	{
		d.x += d.dx;
		d.y += d.dy;
		mlx_pixel_put(init, window, round(d.x), round(d.y), get_color(&g));
		g.color_cur = get_color(&g);
		g.cur_x += d.dx;
		g.cur_y += d.dy;
	}
}

void		draw_line(t_line *line, void *init, void *window)
{
	line_dda(*line, init, window);
	return ;
}
