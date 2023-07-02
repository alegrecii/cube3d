/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:10:50 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/02 18:51:53 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	draw_blocks_helper(t_data *data, int addx, int addy)
{

}
 */
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
