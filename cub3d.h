/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:00:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/16 18:13:14 by alegreci         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define ESC 65307

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

}		t_data;

void	map_conversion(t_data *data, char *path);
int		check_arg(char **str);
void	ft_free_all_map(char **all_map);
void	save_path_text(t_data *data, char **all_map);
void	save_fc_color(t_data *data, char **all_map);
int		super_exit(t_data *data);
void	game_starter(t_data *data);
int		input_manager(int keycode, t_data *data);
int		updater(t_data *data);

#endif

