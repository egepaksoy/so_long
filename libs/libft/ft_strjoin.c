/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:46:45 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/11 20:11:38 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
	{
		*(ret + i) = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		*(ret + i) = *s2;
		i++;
		s2++;
	}
	*(ret + i) = 0;
	return (ret);
}

// girilen s1 ve s2 stringlerini yeni olusturdugu ret listesinin icine yazıyor