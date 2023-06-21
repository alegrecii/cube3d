/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:26:21 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/21 17:00:49 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_calculator(t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->side_distx = (ray->posx - ray->mapx) * ray->delta_distx;
	}
	else
	{
		ray->stepx = 1;
		ray->side_distx = (ray->posx + 1.0 - ray->mapx) * ray->delta_distx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->side_disty = (ray->posy - ray->mapy) * ray->delta_disty;
	}
	else
	{
		ray->stepy = 1;
		ray->side_disty = (ray->posy + 1.0 - ray->mapy) * ray->delta_disty;
	}
}

t_ray	ray_init(t_data *data, int col)
{
	t_ray	ray;
	double	camerax;

	camerax = 2 * col / (double)WIDTH - 1;
	ray.posx = data->cam_state.posx;
	ray.posy = data->cam_state.posy;
	ray.dirx = data->cam_state.dirx + data->cam_state.camx * camerax;
	ray.diry = data->cam_state.diry + data->cam_state.camy * camerax;
	ray.delta_distx = sqrt(1 + (ray.diry * ray.diry) / (ray.dirx * ray.dirx));
	ray.delta_disty = sqrt(1 + (ray.dirx * ray.dirx) / (ray.diry * ray.diry));
	ray.mapx = (int)ray.posx;
	ray.mapy = (int)ray.posy;
	ray_calculator(&ray);
	return (ray);
}

void	ray_launcher(t_data *data, t_ray *ray)
{
	while (data->map[ray->mapy][ray->mapx] == '0')
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_distx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_disty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->len = fabs((ray->mapx - ray->posx + \
		(1 - ray->stepx) / 2) / ray->dirx);
	else
		ray->len = fabs((ray->mapy - ray->posy + \
		(1 - ray->stepy) / 2) / ray->diry);
}

void	col_drawer(t_data *data, t_ray *ray, int col, int y)
{
	int	col_h;
	int	crop_up;
	int	crop_down;

	col_h = abs((int)(HEIGHT / ray->len));
	crop_up = 0;
	crop_down = 0;
	if (col_h > HEIGHT)
	{
		y = 0;
		crop_up = (col_h - HEIGHT) / 2;
		crop_down = crop_up + 1;
	}
	else
	{
		y = ((HEIGHT - col_h) / 2);
		crop_down = 0;
		crop_up = 0;
	}
	while (crop_up < (col_h - crop_down))
	{
		my_mlx_pixel_put(&data->screen, col, y, 4363463);
		y++;
		crop_up++;
	}
	(void)crop_down;
}

void	raycaster(t_data *data)
{
	int		col;
	t_ray	ray;

	col = 0;
	while (col < WIDTH)
	{

		ray = ray_init(data, col);
		ray_launcher(data, &ray);
		col_drawer(data, &ray, col, 0);
		col++;
	}
	(void)ray;
}
