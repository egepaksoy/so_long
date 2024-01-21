/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:34:58 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/13 19:11:53 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*add;

	add = malloc(count * size);
	if (!add)
		return (add);
	ft_bzero(add, count * size);
	return (add);
}

// count byte olan size uzunlugunda bir bellek alanı acıyor
// ve bu alanı null karakterler ile dolduruyor