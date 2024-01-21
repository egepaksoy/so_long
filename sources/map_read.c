/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:28:33 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 00:09:19 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	x_count(char *map_path)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	while (line[x])
		x++;
	free(line);
	close(fd);
	return (x);
}

int	y_count(char *map_path)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(map_path, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y++;
		free(line);
	}
	free(line);
	close(fd);
	return (y);
}

char	**map_read(char *map_path, t_mlx *mlx)
{
	int		y_line;
	char	**total;
	char	*line;
	int		fd;

	mlx->map->x = x_count(map_path);
	mlx->map->y = y_count(map_path);
	fd = open(map_path, O_RDONLY);
	total = (char **)malloc(sizeof(char *) * mlx->map->y + 1);
	if (!total)
		return (0);
	y_line = 0;
	while (y_line < mlx->map->y)
	{
		line = get_next_line(fd);
		total[y_line] = ft_strtrim(line, "\n");
		free(line);
		y_line++;
	}
	total[y_line] = NULL;
	close(fd);
	return (total);
}
