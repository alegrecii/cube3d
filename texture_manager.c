/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:59:55 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/29 12:53:32 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_darker(int color, double len)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if (len < 1)
		return (color);
	r /= len / 1;
	g /= len / 1;
	b /= len / 1;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	color_chooser(t_img	i, int tex_y, t_data *data)
{
	int		tex_x;
	int		color;

	tex_x = data->tex_x;
	if (tex_x >= 0 && tex_x < i.w && tex_y >= 0 && tex_y < i.h)
		color = *(int *)(i.addr + (4 * i.w * tex_y) + (4 * tex_x));
	color = color_darker(color, data->ray->len);
	return (color);
}

t_img	texture_chooser(t_ray *ray, t_data *data)
{
	if (ray->is_door)
		return (data->door);
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
	step = 1.0 * i.h / data->col_h;
	tex_pos = (crop_up - PITCH - HEIGHT / 2 + data->col_h / 2) * step;
	while (crop_up < data->col_h - crop_down)
	{
		tex_y = (int)(((double)crop_up / (double)data->col_h * i.h));
		tex_pos += step;
		my_mlx_pixel_put(&data->screen, data->ray->col, y, color_chooser(i, tex_y, data));
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
		hit_wall = ray->posy + ray->len * ray->diry;
	else
		hit_wall = ray->posx + ray->len * ray->dirx;
	hit_wall = hit_wall - floor(hit_wall);
	tex_x = (int)(hit_wall * (double)i.w);
	if ((ray->side == 0 && ray->dirx > 0) || (ray->side == 1 && ray->diry < 0))
		tex_x = i.w - tex_x - 1;
	return (tex_x);
}
