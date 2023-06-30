/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:00:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/30 20:23:47 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "Get_Next_Line/get_next_line.h"
# include <sys/types.h>
# include "mlx/mlx.h"
# include <math.h>

# define D_KEY 100
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define P_KEY 112
# define E_KEY 101
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define WIDTH 1920
# define HEIGHT 1080
# define MINI_CONST 7.3
# define PITCH 100
# define SPEED 0.1
# define ROT 0.05
# define ROT_MOUSE 0.03
# define ESC 65307
# define FOV 0.66

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	len;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		col;
	int		is_door;
}		t_ray;

typedef struct s_cam
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	camx;
	double	camy;
}		t_cam;

typedef struct s_mini
{
	int	starty;
	int	startx;
	int	endx;
	int	endy;
	int	l;
}		t_mini;

typedef struct s_data
{
	void			*win;
	void			*mlx;
	char			**map;
	char			**path_text;
	char			**fc_color;
	unsigned int	ceiling;
	unsigned int	floor;
	int				p;
	int				col_h;
	int				tex_x;
	int				flood_check;
	int				map_err;
	t_img			screen;
	t_cam			cam_state;
	t_mini			minimap;
	t_img			no;
	t_img			so;
	t_img			ea;
	t_img			we;
	t_img			door;
	t_img			*fire;
	t_ray			*ray;
}		t_data;


int		map_conversion(t_data *data, char *path);
int		check_arg(char **str);
void	ft_free_all_map(char **all_map);
int		counter_map(char **all_map, int i);
void	save_path_text(t_data *data, char **all_map);
char	*texture_cleaner(char *orig);
void	save_fc_color(t_data *data, char **all_map);
int		super_exit(t_data *data);
void	game_starter(t_data *data);
int		input_manager(int keycode, t_data *data);
void	p_esc_keys(int keycode, t_data *data);
int		rotator(int keycode, t_data *data);
int		updater(t_data *data);
int		cam_init(t_data *data);
void	raycaster(t_data *data);
void	my_mlx_pixel_put(t_img *screen, int x, int y, unsigned int color);
void	draw_texture(int crop_up, int crop_down, int y, t_data *data);
t_img	texture_chooser(t_ray *ray, t_data *data);
int		texture_calculator(t_ray *ray, t_data *data);
int		color_darker(int color, double len);
void	minimap_manager(t_data *data);
int		mouse_move(int x, int y, t_data *data);
void	texture_init(t_data *data, char *path, t_img *i);
void	animation_manager(t_data *data);
void	init_fire(t_data *data);
int		check_map_manager(t_data *data);
void	check_space_wall(char **check_map);
void	flood_fill(t_data *data, char **map, int row, int col);

#endif

