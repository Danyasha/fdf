/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 05:52:42 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 16:54:44 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	goiso(double *x, double *y, int z, double angle)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(angle);
	*y = (SIGN * z) + (previous_x + previous_y) * sin(angle);
	*x = *x;
	*y = *y;
}

void	rotate_point(t_point_r *t, double angle)
{
	goiso(&(t->x), &(t->y), t->z, angle);
}
