/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:10:50 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/03 12:43:59 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player_helper(t_data *data)
{
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2) - 1, data->minimap.starty + \
	(data->minimap.l / 2), 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2) + 1, data->minimap.starty + \
	(data->minimap.l / 2), 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2), data->minimap.starty + \
	(data->minimap.l / 2) - 1, 0xff0000);
	my_mlx_pixel_put(&data->screen, data->minimap.startx + \
	(data->minimap.l / 2), data->minimap.starty + \
	(data->minimap.l / 2) + 1, 0xff0000);
}
