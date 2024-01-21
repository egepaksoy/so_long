/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:12:00 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 00:11:55 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_images(t_mlx *mlx, int x, int y)
{
	if (mlx->map->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->wall, x * PIXEL, y * PIXEL);
	else if (mlx->map->map[y][x] == '0' || mlx->map->map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->field, x * PIXEL, y * PIXEL);
	else if (mlx->map->map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->coin, x * PIXEL, y * PIXEL);
	else if (mlx->map->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->exit, x * PIXEL, y * PIXEL);
	else if (mlx->map->map[y][x] == 'e')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->xpm->exit_opened, x * PIXEL, y * PIXEL);
}

void	render_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->y)
	{
		x = 0;
		while (x < mlx->map->x)
		{
			put_images(mlx, x, y);
			x++;
		}
		y++;
	}
	x = mlx->player_x;
	y = mlx->player_y;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->xpm->player, x
		* PIXEL, y * PIXEL);
}

int	render(t_mlx **mlx)
{
	render_map(*mlx);
	if ((*mlx)->count_c == 0
		&& (*mlx)->map->map[(*mlx)->player_y][(*mlx)->player_x] == 'e')
		key_codes(ESC, mlx);
	return (0);
}
