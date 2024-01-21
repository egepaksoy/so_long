/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:00:24 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 09:58:19 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	esc_key(t_mlx **mlx)
{
	mlx_destroy_window((*mlx)->mlx, (*mlx)->win);
	free(*mlx);
	exit(0);
	return (0);
}

int	key_codes(int key_code, t_mlx **mlx)
{
	int	x;
	int	y;

	x = (*mlx)->player_x;
	y = (*mlx)->player_y;
	if (key_code == W && (*mlx)->map->map[y + 1][x] != '1' &&
		key_code == W && (*mlx)->map->map[y + 1][x] != 'E')
		go_up(mlx);
	else if (key_code == D && (*mlx)->map->map[y][x + 1] != '1' &&
		key_code == D && (*mlx)->map->map[y][x + 1] != 'E')
		go_right(mlx);
	else if (key_code == A && (*mlx)->map->map[y][x - 1] != '1' &&
		key_code == A && (*mlx)->map->map[y][x - 1] != 'E')
		go_left(mlx);
	else if (key_code == S && (*mlx)->map->map[y - 1][x] != '1' &&
		key_code == S && (*mlx)->map->map[y - 1][x] != 'E')
		go_down(mlx);
	else if (key_code == ESC)
		esc_key(mlx);
	if ((*mlx)->count_c == 0)
	{
		(*mlx)->map->map[(*mlx)->exit_y][(*mlx)->exit_x] = 'e';
		(*mlx)->exit_opened = 1;
	}
	return (0);
}
