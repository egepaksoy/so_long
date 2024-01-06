/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:00:32 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/06 15:26:40 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	go_up(t_mlx **mlx)
{
	(*mlx)->player_y++;
	(*mlx)->move_count++;
	if ((*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] == 'C')
	{
		(*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] = '0';
		(*mlx)->count_c--;
	}
	ft_putstr_fd("move_count: ", 2);
	ft_putnbr_fd((*mlx)->move_count, 2);
	ft_putstr_fd("\n", 2);
}

void	go_down(t_mlx **mlx)
{
	(*mlx)->player_y--;
	(*mlx)->move_count++;
	if ((*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] == 'C')
	{
		(*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] = '0';
		(*mlx)->count_c--;
	}
	ft_putstr_fd("move_count: ", 2);
	ft_putnbr_fd((*mlx)->move_count, 2);
	ft_putstr_fd("\n", 2);
}

void	go_left(t_mlx **mlx)
{
	(*mlx)->player_x--;
	(*mlx)->move_count++;
	if ((*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] == 'C')
	{
		(*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] = '0';
		(*mlx)->count_c--;
	}
	ft_putstr_fd("move_count: ", 2);
	ft_putnbr_fd((*mlx)->move_count, 2);
	ft_putstr_fd("\n", 2);
}

void	go_right(t_mlx **mlx)
{
	(*mlx)->player_x++;
	(*mlx)->move_count++;
	if ((*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] == 'C')
	{
		(*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] = '0';
		(*mlx)->count_c--;
	}
	ft_putstr_fd("move_count: ", 2);
	ft_putnbr_fd((*mlx)->move_count, 2);
	ft_putstr_fd("\n", 2);
}
