/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:51:07 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/22 18:16:49 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	draw_blocks(t_data *data)
{
} */

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
			my_mlx_pixel_put(&data->screen, x, y, 0);
			x++;
		}
		y++;
	}
}

void	minimap_manager(t_data *data)
{
	draw_square(data);
	//draw_blocks(data);
}
