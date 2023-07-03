/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:29:49 by alegreci          #+#    #+#             */
/*   Updated: 2023/07/03 11:57:22 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	dark_calculator(unsigned int floor, int x, int y, t_data *data)
{
	int		r;
	int		g;
	int		b;
	double	dist;

	dist = sqrt(pow(x - 1300, 2) + pow(y - HEIGHT / 2, 2));
	r = (floor >> 16) & 0xFF;
	g = (floor >> 8) & 0xFF;
	b = floor & 0xFF;
	dist /= 30;
	r /= dist;
	g /= dist;
	b /= dist;
	if (r >= 255 || g >= 255 || b >= 255)
		return (data->max_light);
	floor = (r << 16) | (g << 8) | b;
	return (floor);
}

void	floor_darker(t_data *data, t_img *new)
{
	int	x;
	int	y;

	y = 0;
	new->img = mlx_new_image(data->mlx, WIDTH, HEIGHT / 2);
	new->addr = mlx_get_data_addr(new->img, \
	&new->bits_per_pixel, &new->line_length, &new->endian);
	data->max_light = max_light_calculator(data->floor);
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(new, x, y, \
			dark_calculator(data->floor, x, y, data));
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_img *screen, int x, int y, unsigned int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + \
	x * (screen->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y <= HEIGHT / 2)
				my_mlx_pixel_put(&data->screen, x, y, data->ceiling);
			else
				my_mlx_pixel_put(&data->screen, x, y, \
				(*(int *)(data->dark_floor.addr \
				+ WIDTH * (y - 540) * 4 + x * 4)));
			x++;
		}
		y++;
	}
}

int	updater(t_data *data)
{
	draw_background(data);
	raycaster(data);
	minimap_manager(data);
	animation_manager(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
	if (data->p > 0)
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
