/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:43:36 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		st;
	size_t		e;
	char		*news;
	int			i;

	if (s == NULL)
		return (NULL);
	st = 0;
	e = ft_strlen((char*)s);
	if (e == 0)
		return ((char*)s);
	e--;
	while ((s[st] == '\n' || s[st] == '\t' || s[st] == ' ') && s[st] != '\0')
		st++;
	if (&s[st] == &s[(int)ft_strlen((char*)s)])
		return (news = ft_strnew(0));
	while ((s[e] == '\n' || s[e] == '\t' || s[e] == ' ') && s[e] != '\0')
		e--;
	news = ft_strnew((size_t)(e - st + 1));
	if (news == NULL)
		return (NULL);
	i = 0;
	while (st <= e)
		news[i++] = s[st++];
	return (news);
}
