/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:02:44 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/02 18:54:44 by mdi-paol         ###   ########.fr       */
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

void	texture_init(t_data *data, char *path, t_img *i)
{
	i->img = mlx_xpm_file_to_image(data->mlx, path, &i->w, &i->h);
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
	floor_darker(data, &data->dark_floor);
	texture_init(data, data->path_text[0], &data->no);
	texture_init(data, data->path_text[1], &data->so);
	texture_init(data, data->path_text[2], &data->we);
	texture_init(data, data->path_text[3], &data->ea);
	if (!data->no.img || !data->so.img || !data->ea.img || !data->we.img)
	{
		write(1, "Please insert valid textures\n", 30);
		anticipated_exit(data);
	}
	texture_init(data, "./textures/door.xpm", &data->door);
	init_fire(data);
}

int	init_game(t_data *data, char **argv)
{
	data->mlx = NULL;
	if (map_conversion(data, argv[1]))
		return (write(1, "Error: Map error\n", 17));
	if (data->map_err || check_map_manager(data))
	{
		write(1, "Error\n", 6);
		anticipated_exit(data);
	}
	data->mlx = mlx_init();
	image_init(data);
	minimap_init(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3d");
	data->p = 1;
	/* mlx_mouse_hide(data->mlx, data->win); */
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
