/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:41:05 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;

	if (src == dst)
		return (dst);
	d = (char *)dst;
	i = 0;
	if ((char*)src > d)
	{
		while (i < n)
		{
			*(d + i) = *((char*)src + i);
			i++;
		}
	}
	else
	{
		while (n)
		{
			*(d + n - 1) = *((char*)src + n - 1);
			n--;
		}
	}
	return (d);
}
