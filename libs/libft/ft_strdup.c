/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:37:16 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/13 19:13:39 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*c;

	s_len = ft_strlen(s) + 1;
	c = (char *)malloc(sizeof(char) * s_len);
	if (!c)
		return (c);
	ft_memcpy(c, s, s_len);
	return (c);
}

// yeni bir c string'i olusturuyor ve s stringinin uzunlugunda adres ayırıyor
// ardından s'in icindelileri c'ye yazıyor