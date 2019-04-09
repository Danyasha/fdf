/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:18:43 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isin(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int					i;
	long long int		nbr;
	int					negative;
	char				*whitespaces;
	long long int		check;

	whitespaces = "\t \n\v\r\f";
	nbr = 0;
	negative = 1;
	i = 0;
	while (isin(str[i], whitespaces))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	check = 0;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (10 * nbr) + (int)str[i++] - '0';
		if ((nbr / 10) != check)
			return (negative == 1 ? -1 : 0);
		check = nbr;
	}
	return (nbr * negative);
}
