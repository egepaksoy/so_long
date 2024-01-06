/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:29:20 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/06 15:33:30 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_x_button(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map->map[i])
		free(mlx->map->map[i++]);
	free(mlx->map->map);
	free(mlx->map);
	free(mlx->xpm);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	checker(t_mlx **mlx, char *map_path, int argc)
{
	if (argc != 2)
	{
		ft_print_error("wrong number of arguments");
		return (0);
	}
	if (open(map_path, O_RDONLY) == -1)
	{
		ft_print_error("map file not found");
		return (0);
	}
	if (!init_main(mlx, map_path))
	{
		ft_print_error("initiliazation failed");
		return (0);
	}
	if (!map_draw(mlx))
	{
		ft_print_error("Map isn't playable");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*map_path;
	t_mlx	*mlx;

	map_path = argv[1];
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
	{
		free(mlx);
		return (0);
	}
	if (!checker(&mlx, map_path, argc))
	{
		free(mlx);
		return (0);
	}
	mlx_hook(mlx->win, 2, 1L << 0, key_codes, &mlx);
	mlx_loop_hook(mlx->mlx, render, &mlx);
	mlx_hook(mlx->win, 17, 0, ft_x_button, mlx);
	mlx_loop(mlx->mlx);
}
