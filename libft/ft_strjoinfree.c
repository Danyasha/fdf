/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:32:48 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	int		i;

	i = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	newstr = ft_strnew(len1 + len2);
	if (newstr == NULL)
		return (NULL);
	ft_strncat(newstr, s1, len1);
	ft_strncat(newstr, s2, len2);
	free(s1);
	s1 = NULL;
	return (newstr);
}
