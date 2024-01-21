/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:37:35 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 09:34:31 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_draw(t_mlx **mlx)
{
	int	x;
	int	y;

	y = 0;
	if (!map_check(mlx))
		return (0);
	if (!virtual_map(mlx, 0, 0))
		return (0);
	while (y < (*mlx)->map->y)
	{
		x = 0;
		while (x < (*mlx)->map->x - 1)
		{
			if (!map_put_image(*mlx, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	map_put_image(t_mlx *mlx, int x, int y)
{
	if (mlx->map->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->wall, PIXEL * x, PIXEL * y);
	else if (mlx->map->map[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->field, PIXEL * x, PIXEL * y);
	else if (mlx->map->map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->coin, PIXEL * x, PIXEL * y);
	else if (mlx->map->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->exit, PIXEL * x, PIXEL * y);
	else if (mlx->map->map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->player, PIXEL * x, PIXEL * y);
	else if (mlx->map->map[y][x] == 'e')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->exit_opened, PIXEL * x, PIXEL * y);
	else
		return (0);
	return (1);
}
