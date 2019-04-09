/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:40:44 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int ch, size_t n)
{
	unsigned char	c;
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	c = (unsigned char)ch;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		if (s[i] == c)
		{
			*(d + i) = *(s + i);
			i++;
			return (&d[i]);
		}
		*(d + i) = *(s + i);
		i++;
	}
	return (NULL);
}
