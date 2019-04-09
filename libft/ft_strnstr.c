/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:19:18 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		isinlen(char *s1, char *s2, size_t l)
{
	long long	i;
	long long	len2;

	len2 = 0;
	i = 0;
	while (s2[len2] != '\0')
		len2++;
	if ((long long)l < len2)
		return (0);
	while (i < (long long)l && i < len2)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	long long	i;
	long long	l;

	l = (long long)len;
	i = 0;
	len = ft_strlen(little);
	while (big[i] != '\0')
	{
		if (isinlen((char*)&big[i], (char*)little, l))
			return ((char*)&big[i]);
		i++;
		l--;
	}
	return (0);
}
