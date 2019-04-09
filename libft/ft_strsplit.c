/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:49:25 by btorp             #+#    #+#             */
/*   Updated: 2019/04/06 02:56:33 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**freearrays(char **a)
{
	int	i;

	i = 0;
	while (&a[i] != NULL)
		ft_memdel((void**)a[i++]);
	a = NULL;
	return (NULL);
}

static	int		countarrays(char const *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\0' && s[i] == c)
		{
			i++;
			continue;
		}
		else
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (n);
}

static	char	**ft_strsplitmemalloc(char **temp, const char *s, char c)
{
	int		i;
	int		n;
	int		k;

	k = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c && *s != '\0')
		{
			s++;
			continue;
		}
		n = 0;
		while (*s != c && *s != '\0')
		{
			n++;
			s++;
		}
		temp[k] = ft_strnew(n);
		if (temp[k++] == NULL)
			return (NULL);
	}
	return (temp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**temp;
	int		j;

	if (s == NULL)
		return (NULL);
	if (!ft_findch((char*)s, c))
		return (NULL);
	temp = (char**)malloc((countarrays(s, c) + 1) * sizeof(char*));
	if (temp == NULL)
		return (0);
	if (!ft_strsplitmemalloc(temp, s, c))
		return (freearrays(temp));
	j = 0;
	while (*s != '\0')
	{
		if (*s == c && *s++ != '\0')
			continue;
		i = 0;
		while (*s != c && *s != '\0')
			temp[j][i++] = *s++;
		j++;
	}
	temp[j] = NULL;
	return (temp);
}
