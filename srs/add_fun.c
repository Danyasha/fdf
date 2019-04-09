/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:45:40 by btorp             #+#    #+#             */
/*   Updated: 2019/04/08 17:35:16 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	get_number(char c)
{
	char	dict[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int		i;

	i = 0;
	while (i < 16)
	{
		if (dict[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi16(char *str)
{
	int		len;
	int		l;
	int		i;

	return DEFAULT_COLOR;
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