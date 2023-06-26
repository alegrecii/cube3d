/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:29:49 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/26 17:04:36 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *screen, int x, int y, unsigned int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x \
	* (screen->bits_per_pixel / 8));
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
				my_mlx_pixel_put(&data->screen, x, y, data->floor);
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
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
