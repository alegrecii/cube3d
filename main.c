/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:02:44 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/26 17:08:37 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_init(t_data *data)
{
	t_mini	minimap;

	minimap.l = (WIDTH / 25) * 2;
	minimap.starty = HEIGHT / 30;
	minimap.startx = WIDTH / 40;
	minimap.endx = minimap.startx + minimap.l;
	minimap.endy = minimap.starty + minimap.l;
	data->minimap = minimap;
}

void	texture_init(t_data *data, int dir, t_img *i)
{
	int	tmp;

	tmp = 0;
	i->img = mlx_xpm_file_to_image(data->mlx, data->path_text[dir], &tmp, &tmp);
	if (!i->img)
		return ;
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, \
	&i->line_length, &i->endian);
}

void	image_init(t_data *data)
{
	t_img	screen;

	screen.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel, \
	&screen.line_length, &screen.endian);
	data->screen = screen;
	texture_init(data, 0, &data->no);
	texture_init(data, 1, &data->so);
	texture_init(data, 2, &data->we);
	texture_init(data, 3, &data->ea);
}

int	init_game(t_data *data, char **argv)
{
	if (map_conversion(data, argv[1]))
		return (write(1, "Error: Map error\n", 17));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3d");
	image_init(data);
	minimap_init(data);
	mlx_mouse_hide(data->mlx, data->win);
	game_starter(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (check_arg(argv))
			return (write(1, "Error: Map error\n", 17));
		else
			init_game(&data, argv);
	}
	else
		return (write(2, "Error: Bad arguments\n", 21));
}
