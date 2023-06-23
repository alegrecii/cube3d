/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:59:55 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/23 19:59:20 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_chooser(t_ray *ray, t_img *screen, int col, int y)
{
	if (ray->side == 0 && ray->dirx > 0) //E
		my_mlx_pixel_put(screen, col, y, 457474);
	if (ray->side == 0 && ray->dirx < 0) //W
		my_mlx_pixel_put(screen, col, y, 346346);
	if (ray->side == 1 && ray->diry > 0) //S
		my_mlx_pixel_put(screen, col, y, 745745);
	if (ray->side == 1 && ray->diry < 0) //N
		my_mlx_pixel_put(screen, col, y, 567546);
}
