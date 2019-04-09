/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:49:27 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		a->content = NULL;
		a->content_size = 0;
		a->next = NULL;
		return (a);
	}
	a->content = malloc(content_size);
	if (a->content == NULL)
	{
		free(a);
		a = NULL;
		return (NULL);
	}
	a->content = ft_memcpy(a->content, content, content_size);
	a->content_size = content_size;
	a->next = NULL;
	return (a);
}
