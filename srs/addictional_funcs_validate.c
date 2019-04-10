/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addictional_funcs_validate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 01:15:47 by btorp             #+#    #+#             */
/*   Updated: 2019/04/10 15:57:28 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		doesitint(char *str)
{
	int	temp;
	int	i;

	i = 0;
	temp = ft_atoi(str);
	if (temp != 0)
		return (1);
	if (temp == 0 && str[0] == '0')
		return (1);
	return (0);
}

int		does_it_16int(char *str)
{
	int	temp;

	temp = ft_atoi16(&str[2]);
	if (str[0] != '0' || str[1] != 'x' || ft_strlen(str) != 8)
		return (0);
	if (temp < 0)
		return (0);
	return (1);
}

int		free_strstr(char ***str)
{
	char	**temp_str;
	int		i;

	if (*str == NULL)
		return (0);
	temp_str = *str;
	i = 0;
	while (temp_str[i])
		free(temp_str[i++]);
	free(temp_str[i]);
	free(*str);
	return (0);
}

int		array_len(char **a)
{
	int	i;

	if (a == NULL || *a == NULL)
		return (0);
	i = 0;
	while (*a)
	{
		a++;
		i++;
	}
	return (i);
}

t_map	*exiter_validate(t_map **map)
{
	free(*map);
	*map = NULL;
	return (NULL);
}
