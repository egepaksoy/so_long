/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:42:16 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/13 19:12:45 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;

	n = 0;
	while (len > n)
	{
		*(unsigned char *)(b + n) = c;
		n++;
	}
	return (b);
}

// verilen len uzunlugundaki herhangi bir veri tipindeki b dizisinin
// tum elemanlarini verilen c degeri ile degistiriyor