/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplacechr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 02:51:22 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplacechr(const char *src, char to, char what)
{
	char	*newsrc;
	int		i;

	if (src == NULL)
		return (NULL);
	newsrc = ft_strnew(ft_strlen(src));
	if (newsrc == NULL)
		return (NULL);
	i = 0;
	while (*src)
	{
		if (*src == to)
			newsrc[i] = what;
		else
			newsrc[i] = *src;
		src++;
		i++;
	}
	return (newsrc);
}
