/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:48:15 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 09:57:47 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <math.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	key_press(int key, void *param)
{
	void	**s;
	static int j;
	int			color;
	
	s = (void**)param;
	if (key != 18 && key != 19)
		return 0;
	if (key == 18)
		color = 0x121F1;
	else
		color = 0xFC0FC0;
	mlx_string_put(s[0], s[1], j, j, color, "Ti Pidor");
	j += 12;
	return 0;
}
void	fill(void *init, void *w, int c)
{
	for(int i = 0; i<= WINDOW_HEIGHT; i++)
	{
		for (int j = 0; j<= WINDOW_WIDTH; j++)
		{
			mlx_pixel_put(init, w, i, j, c);
		}
	}
	
}

int	main (void)
{
	void	*init;
	void	*new_wi;
	void	*s[2];
	
	init = mlx_init();
	new_wi = mlx_new_window(init, WINDOW_WIDTH, WINDOW_HEIGHT, "TI PIDOR");
	s[0] = init;
	s[1] = new_wi;
	mlx_hook(new_wi, 2, 18, key_press, s);
	mlx_loop(init);
	return 0;
}