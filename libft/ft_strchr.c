/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:19:42 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	s;
	int		k;

	k = 0;
	i = 0;
	s = (char)c;
	while (str[k] != '\0')
		k++;
	if (s == '\0')
		return ((char*)&str[k]);
	while (str[i] != '\0')
	{
		if (str[i] == s)
			return ((char*)&str[i]);
		i++;
	}
	return (0);
}
