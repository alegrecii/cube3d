/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:59:55 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/26 20:41:15 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_chooser(t_img	i, int tex_y, t_data *data, t_ray *ray)
{
	int	tex_x;

	tex_x = texture_calculator(ray, data);
	if (tex_x >= 0 && tex_x < i.w && tex_y >= 0 && tex_y < i.h)
		return (*(int *)i.addr + (4 * i.w * tex_y) + (4 * tex_x));
	return (0);
}

/* int	draw_texture(t_data *data, t_ray *ray, int flag)
{
	double	hit_wall;

	if (flag == 3 || flag == 2)
		hit_wall = ray->posx + ray->len * ray->diry;
	else
		hit_wall = ray->posx + ray->len * ray->dirx;
	hit_wall = hit_wall - floor(hit_wall);
} */

t_img	texture_chooser(t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->dirx > 0) //E
		return (data->ea);
	if (ray->side == 0 && ray->dirx < 0) //W
		return (data->we);
	if (ray->side == 1 && ray->diry > 0) //S
		return (data->so);
	if (ray->side == 1 && ray->diry < 0) //N
		return (data->no);
	return (data->no);
}

void	draw_texture(int crop_up, int crop_down, int y, t_data *data)
{
	t_img	i;
	double	step;
	double	tex_pos;
	int		tex_y;

	i = texture_chooser(data->ray, data);
	step = 1.0 * i.w / abs((int)(HEIGHT / data->ray->len));
	tex_pos = (crop_up - PITCH - HEIGHT / 2 + data->ray->len / 2) * step;
	while (crop_up < (abs((int)(HEIGHT / data->ray->len) - crop_down)))
	{
		tex_y = (int)tex_pos & (i.h - 1);
		tex_pos += step;
		my_mlx_pixel_put(&data->screen, data->ray->col, y, color_chooser(i, tex_y, data, data->ray));
		y++;
		crop_up++;
	}
	(void)crop_up;
}

int	texture_calculator(t_ray *ray, t_data *data)
{
	double	hit_wall;
	int		tex_x;
	t_img	i;

	i = texture_chooser(ray, data);
	if (ray->side == 0)
		hit_wall = ray->posx + ray->len * ray->diry;
	else
		hit_wall = ray->posx + ray->len * ray->dirx;
	hit_wall = hit_wall - floor(hit_wall);
	tex_x = (int)(hit_wall * (double)i.w);
	if ((ray->side == 0 && ray->dirx > 0) || (ray->side == 1 && ray->diry < 0))
		tex_x = i.w - tex_x - 1;
	return (tex_x);
}

/* void	texture_chooser(t_ray *ray, t_data *data, int crop_up, int crop_down)
{
	if (ray->side == 0 && ray->dirx > 0) //E
		my_mlx_pixel_put(&data->screen, col, y, draw_texture(data, ray, 3));
	if (ray->side == 0 && ray->dirx < 0) //W
		my_mlx_pixel_put(&data->screen, col, y, draw_texture(data, ray, 2));
	if (ray->side == 1 && ray->diry > 0) //S
		my_mlx_pixel_put(&data->screen, col, y, draw_texture(data, ray, 1));
	if (ray->side == 1 && ray->diry < 0) //N
		my_mlx_pixel_put(&data->screen, col, y, draw_texture(data, ray, 0));
} */
