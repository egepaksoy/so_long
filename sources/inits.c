/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:29:12 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 00:19:05 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_main(t_mlx **mlx, char *map_path)
{
	(*mlx)->mlx = mlx_init();
	(*mlx)->map = (t_map *)malloc(sizeof(t_map));
	if (!(*mlx)->map)
		return (0);
	(*mlx)->map->map = map_read(map_path, *mlx);
	(*mlx)->count_p = 0;
	(*mlx)->count_c = 0;
	(*mlx)->count_e = 0;
	(*mlx)->move_count = 0;
	(*mlx)->read_count = 0;
	(*mlx)->player_y = 0;
	(*mlx)->player_x = 0;
	(*mlx)->win = mlx_new_window((*mlx)->mlx, ((*mlx)->map->x - 1) * PIXEL,
			(*mlx)->map->y * PIXEL, "so_long");
	(*mlx)->xpm = (t_xpm *)malloc(sizeof(t_xpm));
	if (!(*mlx)->xpm)
	{
		free((*mlx)->xpm);
		return (0);
	}
	init_xpm(mlx);
	return (1);
}

int	init_xpm(t_mlx **mlx)
{
	(*mlx)->xpm->field = mlx_xpm_file_to_image((*mlx)->mlx,
			"./images/xpm/field1x32.xpm", &(*mlx)->xpm->width,
			&(*mlx)->xpm->height);
	(*mlx)->xpm->wall = mlx_xpm_file_to_image((*mlx)->mlx,
			"./images/xpm/wall32.xpm", &(*mlx)->xpm->width,
			&(*mlx)->xpm->height);
	(*mlx)->xpm->coin = mlx_xpm_file_to_image((*mlx)->mlx,
			"./images/xpm/coin_bg32.xpm", &(*mlx)->xpm->width,
			&(*mlx)->xpm->height);
	(*mlx)->xpm->exit = mlx_xpm_file_to_image((*mlx)->mlx,
			"./images/xpm/exit_closed_bg32.xpm", &(*mlx)->xpm->width,
			&(*mlx)->xpm->height);
	(*mlx)->xpm->player = mlx_xpm_file_to_image((*mlx)->mlx,
			"./images/xpm/knight_front_bg32.xpm", &(*mlx)->xpm->width,
			&(*mlx)->xpm->height);
	(*mlx)->xpm->exit_opened = mlx_xpm_file_to_image((*mlx)->mlx,
			"./images/xpm/exit_opened_bg32.xpm", &(*mlx)->xpm->width,
			&(*mlx)->xpm->height);
	if (!(*mlx)->xpm->field || !(*mlx)->xpm->wall || !(*mlx)->xpm->coin
		|| !(*mlx)->xpm->exit || !(*mlx)->xpm->player)
		return (0);
	return (1);
}
