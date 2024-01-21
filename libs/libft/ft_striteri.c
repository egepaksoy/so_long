/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:31:11 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/12 17:44:24 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// verilen s string'inin adreslerindeki degerlerini f
// fonksiyonunun dondurdugu degerlerle degistiriyor