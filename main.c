/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:02:44 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/19 18:23:02 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_init(t_data *data)
{
	t_img	screen;

	screen.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel, \
	&screen.line_length, &screen.endian);
	data->screen = screen;
}

int	init_game(t_data *data, char **argv)
{
	if (map_conversion(data, argv[1]))
		return (write(1, "Error: Map error\n", 17));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3d");
	image_init(data);
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
