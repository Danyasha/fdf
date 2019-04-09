/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:40:29 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf, const void *buf2, size_t count)
{
	unsigned char	*big;
	unsigned char	*little;

	big = (unsigned char*)buf;
	little = (unsigned char*)buf2;
	if (count == 0)
		return (0);
	if (*big && *little && !count)
		return (0);
	while (count--)
	{
		if (*big != *little)
			return (*big - *little);
		little++;
		big++;
	}
	return (0);
}
