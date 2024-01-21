/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:03:43 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 09:09:59 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_or_exit(int x, int y, t_mlx **mlx)
{
	if ((*mlx)->map->map[y][x] == 'P')
	{
		(*mlx)->player_x = x;
		(*mlx)->player_y = y;
		(*mlx)->map->map[y][x] = '0';
		(*mlx)->count_p++;
	}
	else if ((*mlx)->map->map[y][x] == 'E')
	{
		(*mlx)->exit_x = x;
		(*mlx)->exit_y = y;
		(*mlx)->count_e++;
	}
}

int	count_all(t_mlx **mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*mlx)->map->y)
	{
		x = 0;
		while (x < (*mlx)->map->x)
		{
			if ((*mlx)->map->map[y][x] == 'P' || (*mlx)->map->map[y][x] == 'E')
				player_or_exit(x, y, mlx);
			if ((*mlx)->map->map[y][x] == 'C')
				(*mlx)->count_c++;
			if ((*mlx)->map->map[y][x] == '1')
				(*mlx)->count_w++;
			x++;
		}
		y++;
	}
	return (1);
}

int	map_check(t_mlx **mlx)
{
	int	y;
	int	x;
	int	first_line;

	y = 0;
	first_line = 0;
	while (y < (*mlx)->map->y)
	{
		x = ft_strlen((*mlx)->map->map[y]);
		if (first_line != x && first_line)
			return (0);
		first_line = x;
		y++;
	}
	if (y != (*mlx)->map->y)
		return (0);
	count_all(mlx);
	if ((*mlx)->count_p != 1 || (*mlx)->count_e != 1
		|| (*mlx)->count_c < 1 || (*mlx)->count_w < 1)
		return (0);
	return (1);
}
