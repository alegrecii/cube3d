/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:51:07 by alegreci          #+#    #+#             */
/*   Updated: 2023/07/03 12:43:45 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_data *data)
{
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2), data->minimap.starty + \
	(data->minimap.l / 2), 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2) - 1, data->minimap.starty + \
	(data->minimap.l / 2) - 1, 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2) + 1, data->minimap.starty + \
	(data->minimap.l / 2) - 1, 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2) - 1, data->minimap.starty + \
	(data->minimap.l / 2) + 1, 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2) + 1, data->minimap.starty + \
	(data->minimap.l / 2) + 1, 0xff0000);
	put_player_helper(data);
}

int	check_limits_minimap(t_data *data, double addx, double addy, char c)
{
	if (addx < 0 || (int)addx >= (int)ft_strlen(data->map[0]))
		return (0);
	if (addy < 0 || (int)addy >= counter_map(data->map, 0))
		return (0);
	if (data->map[(int)(addy)][(int)(addx)] == c)
		return (1);
	return (0);
}

void	draw_blocks(t_data *data, int y, int x)
{
	double	addx;
	double	addy;

	addy = data->cam_state.posy - MINI_CONST;
	while (y < (data->minimap.endy - 3))
	{
		addx = data->cam_state.posx - MINI_CONST;
		x = data->minimap.startx + 3;
		while (x < (data->minimap.endx - 3))
		{
			if (check_limits_minimap(data, addx, addy, '0'))
				my_mlx_pixel_put(&data->screen, x, y, data->ceiling);
			else if (check_limits_minimap(data, addx, addy, 'D'))
				my_mlx_pixel_put(&data->screen, x, y, 0x960c0c);
			else if (check_limits_minimap(data, addx, addy, 'O'))
				my_mlx_pixel_put(&data->screen, x, y, 0x28965a);
			else
				my_mlx_pixel_put(&data->screen, x, y, 0xd8ebfd);
			x++;
			addx += SPEED;
		}
		y++;
		addy += SPEED;
	}
	put_player(data);
}

void	draw_square(t_data *data)
{
	int	y;
	int	x;

	y = data->minimap.starty;
	while (y < data->minimap.endy)
	{
		x = data->minimap.startx;
		while (x < data->minimap.endx)
		{
			my_mlx_pixel_put(&data->screen, x, y, 0xa0a0a0);
			x++;
		}
		y++;
	}
}

void	minimap_manager(t_data *data)
{
	draw_square(data);
	draw_blocks(data, data->minimap.starty + 3, data->minimap.startx);
}
