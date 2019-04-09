/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:01:01 by btorp             #+#    #+#             */
/*   Updated: 2019/03/21 20:19:44 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <stdio.h>
int	main()
{
	void	*init;
	void	*window;
	void	*window2;
	t_line	*line;
	init = mlx_init();
	window = mlx_new_window(init, 1000, 1000, "TI PIDOR");
	// for (double i = 400; i < 500; i++)
	// 	mlx_pixel_put(init, window, i, i * 1.2, 0xDFFF1);
	line = (t_line*)malloc(sizeof(t_line));
	line->x0 = 150;
	line->x1 = 250;
	line->y0 = 150;
	line->y1 = 200;
	draw_line(line, init, window);
	mlx_loop(init);
	return (0);
}