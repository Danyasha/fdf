/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 02:31:50 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *s)
{
	int		i;
	char	*news;

	if (s == NULL)
		return (NULL);
	news = ft_strnew(ft_strlen(s));
	if (news == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		news[i++] = ft_tolower(*s);
		s++;
	}
	return (news);
}
