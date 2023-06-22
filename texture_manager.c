/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:59:55 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/22 14:50:28 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_chooser(t_ray *ray, t_img *screen, int col, int y)
{
	if (ray->side == 0)//N
		my_mlx_pixel_put(screen, col, y, 4363463);
/* 	if (ray->side == 0 && ray->diry > 0)//S
		my_mlx_pixel_put(screen, col, y, 12545891);
	if (ray->side == 1 && ray->dirx < 0)//W
		my_mlx_pixel_put(screen, col, y, 8593212); */
	if (ray->side == 1)//E
		my_mlx_pixel_put(screen, col, y, 1235773);

}
