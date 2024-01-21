/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:29:35 by epaksoy           #+#    #+#             */
/*   Updated: 2024/01/21 09:36:19 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>

# define PIXEL 32

# define ESC 53
# define W 1
# define A 0
# define S 13
# define D 2

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_xpm
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*field;
	void	*exit;
	void	*exit_opened;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_w;
	int		move_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit_opened;
	int		read_count;
	t_xpm	*xpm;
}	t_mlx;

int		ft_x_button(t_mlx *main);

int		init_main(t_mlx **mlx, char *map_path);
int		init_xpm(t_mlx **mlx);

int		x_count(char *map_path);
int		y_count(char *map_path);
char	**map_read(char *map_path, t_mlx *mlx);

int		map_check(t_mlx **mlx);
int		count_all(t_mlx **mlx);

int		map_draw(t_mlx **mlx);
int		map_put_image(t_mlx *mlx, int x, int y);

int		key_codes(int key_code, t_mlx **mlx);
int		esc_key(t_mlx **mlx);

void	go_right(t_mlx **mlx);
void	go_left(t_mlx **mlx);
void	go_down(t_mlx **mlx);
void	go_up(t_mlx **mlx);

int		render(t_mlx **mlx);
void	render_map(t_mlx *mlx);

int		ft_print_error(char *str);
void	virtual_map_free(int **v_map, t_mlx *mlx);

int		virtual_map(t_mlx **mlx, int y, int x);

#endif