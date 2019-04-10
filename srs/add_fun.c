/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:45:40 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 16:55:23 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static	void	make_d(char *s)
{
	s[0] = '0';
	s[1] = '1';
	s[2] = '2';
	s[3] = '3';
	s[4] = '4';
	s[5] = '5';
	s[6] = '6';
	s[7] = '7';
	s[8] = '8';
	s[9] = '9';
	s[10] = 'A';
	s[11] = 'B';
	s[12] = 'C';
	s[13] = 'D';
	s[14] = 'E';
	s[15] = 'F';
}

static	int		get_number(char c)
{
	char	dict[17];
	int		i;

	make_d((char*)&dict);
	i = 0;
	while (i < 16)
	{
		if (dict[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi16(char *str)
{
	int		len;
	int		l;
	int		i;

	i = 1;
	len = ft_strlen(str);
	l = 0;
	while (len)
	{
		if (get_number(str[len - 1]) < 0)
			return (-1);
		l = l + (get_number(str[len - 1]) * i);
		i = i * 16;
		len--;
	}
	return (l);
}
