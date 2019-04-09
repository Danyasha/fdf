/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:32:05 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*temp;

	if (alst == NULL)
		return ;
	temp = *alst;
	while (temp != NULL)
	{
		next = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = next;
	}
	*alst = NULL;
}
