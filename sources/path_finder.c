/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:48:23 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/06 15:52:12 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	path_finding(int **v_map, t_mlx **mlx, int y, int x)
{
	if ((*mlx)->map->map[y][x] == 'E' || (*mlx)->map->map[y][x] == 'C')
		(*mlx)->read_count++;
	if ((*mlx)->map->map[y - 1][x] != '1' && v_map[y - 1][x] < 1)
	{
		v_map[y - 1][x] = v_map[y][x] + 1;
		path_finding(v_map, mlx, y - 1, x);
	}
	if ((*mlx)->map->map[y][x - 1] != '1' && v_map[y][x - 1] < 1)
	{
		v_map[y][x - 1] = v_map[y][x] + 1;
		path_finding(v_map, mlx, y, x - 1);
	}
	if ((*mlx)->map->map[y + 1][x] != '1' && v_map[y + 1][x] < 1)
	{
		v_map[y + 1][x] = v_map[y][x] + 1;
		path_finding(v_map, mlx, y + 1, x);
	}
	if ((*mlx)->map->map[y][x + 1] != '1' && v_map[y][x + 1] < 1)
	{
		v_map[y][x + 1] = v_map[y][x] + 1;
		path_finding(v_map, mlx, y, x + 1);
	}
}

int	ret_val(int ***v_map)
{
	free(v_map);
	return (0);
}

int	**v_map_ret(t_mlx **mlx, int y, int x)
{
	int	**v_map;

	v_map = (int **)malloc(sizeof(int *) * (*mlx)->map->y);
	if (!v_map)
		return (0);
	while (y < (*mlx)->map->y)
	{
		v_map[y] = (int *)malloc(sizeof(int) * (*mlx)->map->x);
		if (!v_map[y])
		{
			free(v_map);
			return (0);
		}
		x = 0;
		while (x < (*mlx)->map->x)
		{
			v_map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (v_map);
}

int	virtual_map(t_mlx **mlx, int y, int x)
{
	int	**v_map;

	v_map = v_map_ret(mlx, y, x);
	if (!v_map)
	{
		free(v_map);
		return (0);
	}
	if (!map_check(mlx))
		return (0);
	v_map[(*mlx)->player_y][(*mlx)->player_x] = 1;
	path_finding(v_map, mlx, (*mlx)->player_y, (*mlx)->player_x);
	if ((*mlx)->read_count != (*mlx)->count_c + 1)
	{
		free(v_map);
		return (0);
	}
	return (1);
}
