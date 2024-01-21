/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:00:26 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/16 16:17:53 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (!lst || !f)
		return (0);
	begin = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}

// lstdeki elemanları f fonksiyonuna sokar donen degerleri
// yeni bir listeye atar ve listenin baslangıcını dondurur