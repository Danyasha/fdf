/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:40:13 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		intlen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

static	char	makechar(int *n)
{
	char	a;

	a = *n % 10 + '0';
	*n /= 10;
	return (a);
}

static	char	*minint(void)
{
	char	*temp;
	char	*a;
	int		i;

	i = 0;
	a = "-2147483648";
	temp = ft_strnew(11);
	while (i < 11)
	{
		temp[i] = a[i];
		i++;
	}
	return (temp);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	if (n == -2147483648)
		return (minint());
	i = intlen(n) - 1;
	nbr = ft_strnew(i + 1);
	if (nbr == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		nbr[0] = '-';
	}
	while (n >= 10)
		nbr[i--] = makechar(&n);
	nbr[i] = n + '0';
	return (nbr);
}
