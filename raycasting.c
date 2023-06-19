/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:26:21 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/19 19:00:33 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	ray_init(t_data *data, int col)
{
	t_ray	ray;
	double	camerax;

	camerax = 2 * col / (double)WIDTH - 1;
	ray.posx = data->cam_state.posx;
	ray.posy = data->cam_state.posy;
	ray.dirx = data->cam_state.dirx + data->cam_state.camx * camerax;
	ray.diry = data->cam_state.diry + data->cam_state.camy * camerax;
	return (ray);
}

void	raycaster(t_data *data)
{
	int		col;
	t_ray	ray;

	col = 0;
	while (col < WIDTH)
	{
		ray = ray_init(data, col);
		/* ray = ray_launcher();
		ray_drawer(&ray); */
		col++;
	}
	(void)ray;
}
