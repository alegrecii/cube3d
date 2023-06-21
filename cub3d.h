/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:00:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/21 17:17:26 by alegreci         ###   ########.fr       */
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
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
/* # define WIDTH 1920
# define HEIGHT 1080 */
# define WIDTH 640
# define HEIGHT 480
# define SPEED 0.1
# define ROT 0.05
# define ESC 65307
# define FOV 0.66

/* typedef struct s_images
{
	t_img	*screen;
}		t_images; */

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

typedef struct s_data
{
	void			*win;
	void			*mlx;
	char			**map;
	char			**path_text;
	char			**fc_color;
	unsigned int	ceiling;
	unsigned int	floor;
	t_img			screen;
	t_cam			cam_state;
}		t_data;


int		map_conversion(t_data *data, char *path);
int		check_arg(char **str);
void	ft_free_all_map(char **all_map);
void	save_path_text(t_data *data, char **all_map);
void	save_fc_color(t_data *data, char **all_map);
int		super_exit(t_data *data);
void	game_starter(t_data *data);
int		input_manager(int keycode, t_data *data);
int		updater(t_data *data);
int		cam_init(t_data *data);
void	raycaster(t_data *data);
void	my_mlx_pixel_put(t_img *screen, int x, int y, unsigned int color);
#endif

