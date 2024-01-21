/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:19:27 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 09:37:09 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

void	virtual_map_free(int **v_map, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->y)
	{
		free(v_map[i]);
		i++;
	}
	free(v_map);
}
