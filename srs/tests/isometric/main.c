/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:06:40 by btorp             #+#    #+#             */
/*   Updated: 2019/03/01 20:29:42 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <math.h>

int		main()
{
	void	*init;
	void	*window, *window2;
	double	n;
	double isox;
	double isoy;
	
	init = mlx_init();
	window2 = mlx_new_window(init, 900, 900, "TI PIDOR");
	window = mlx_new_window(init, 900, 900, "TI PIDOR");
	double yh = 150;
	for (int i = 400; i < 500; i++)
	{
		mlx_pixel_put(init, window, i, yh, 0xDFFF1);
		isox = i - yh;
		isoy = (i + yh) / 2;
		mlx_pixel_put(init, window2, isox, isoy, 0xAAAF1);
		mlx_pixel_put(init, window2, isox + 100, isoy + 100, 0xAAAF1);
		mlx_pixel_put(init, window2, isox - 100, isoy - 100, 0xAAAF1);
	}
	yh = 250;
	for (int i = 400; i < 500; i++)
	{
		mlx_pixel_put(init, window, i, yh, 0xDFFF1);
		isox = i - yh;
		isoy = (i + yh) / 2;
		mlx_pixel_put(init, window2, isox, isoy, 0xAAAF1);
		mlx_pixel_put(init, window2, isox + 100, isoy + 100, 0xAAAF1);
		mlx_pixel_put(init, window2, isox - 100, isoy - 100, 0xAAAF1);
	}
	yh = 400;
	for (int i = 150; i < 250; i++)
	{
		mlx_pixel_put(init, window, yh, i, 0xDFFF1);
		isox = yh - i;
		isoy = (i + yh) / 2;
		mlx_pixel_put(init, window2, isox, isoy, 0xAAAF1);
		mlx_pixel_put(init, window2, isox + 100, isoy + 100, 0xAAAF1);
		mlx_pixel_put(init, window2, isox - 100, isoy - 100, 0xAAAF1);
	}
	yh = 500;
	for (int i = 150; i < 250; i++)
	{
		mlx_pixel_put(init, window, yh, i, 0xDFFF1);
		isox = yh - i;
		isoy = (i + yh) / 2;
		mlx_pixel_put(init, window2, isox, isoy, 0xAAAF1);
		mlx_pixel_put(init, window2, isox + 100, isoy + 100, 0xAAAF1);
		mlx_pixel_put(init, window2, isox - 100, isoy - 100, 0xAAAF1);
	}
	mlx_loop(init);
	return 0;
}