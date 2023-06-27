/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:32:44 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/27 11:31:00 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_data *data, int keycode)
{
	double wall_dist;

	wall_dist = 0.1;
	if (keycode == W_KEY && data->map[(int)(data->cam_state.posy + data->cam_state.diry * (SPEED + wall_dist))][(int)(data->cam_state.posx + data->cam_state.dirx * (SPEED + wall_dist))] != '1')
		return(1);
	if (keycode == S_KEY && data->map[(int)(data->cam_state.posy - data->cam_state.diry * (SPEED + wall_dist))][(int)(data->cam_state.posx - data->cam_state.dirx * (SPEED + wall_dist))] != '1')
		return(1);
	if (keycode == D_KEY && data->map[(int)(data->cam_state.posy + data->cam_state.dirx * (SPEED + wall_dist))][(int)(data->cam_state.posx - data->cam_state.diry * (SPEED + wall_dist))] != '1')
		return(1);
	if (keycode == A_KEY && data->map[(int)(data->cam_state.posy - data->cam_state.dirx * (SPEED + wall_dist))][(int)(data->cam_state.posx + data->cam_state.diry * (SPEED + wall_dist))] != '1')
		return(1);
	return(0);
}

void	rotator(int keycode, t_data *data)
{
	double	dirx;
	double	camx;

	camx = data->cam_state.camx;
	dirx = data->cam_state.dirx;

	if (keycode == ARROW_RIGHT)
	{
		data->cam_state.dirx = data->cam_state.dirx * \
		cos(ROT) - data->cam_state.diry * sin(ROT);
		data->cam_state.diry = dirx * sin(ROT) + \
		data->cam_state.diry * cos(ROT);
		data->cam_state.camx = data->cam_state.camx * \
		cos(ROT) - data->cam_state.camy * sin(ROT);
		data->cam_state.camy = camx * sin(ROT) + \
		data->cam_state.camy * cos(ROT);
	}
	if (keycode == ARROW_LEFT)
	{
		data->cam_state.dirx = data->cam_state.dirx * \
		cos(-ROT) - data->cam_state.diry * sin(-ROT);
		data->cam_state.diry = dirx * sin(-ROT) + \
		data->cam_state.diry * cos(-ROT);
		data->cam_state.camx = data->cam_state.camx * \
		cos(-ROT) - data->cam_state.camy * sin(-ROT);
		data->cam_state.camy = camx * sin(-ROT) + \
		data->cam_state.camy * cos(-ROT);
	}
}

int	input_manager(int keycode, t_data *data)
{
	if (keycode == W_KEY && check_wall(data, keycode))
	{
		data->cam_state.posx += data->cam_state.dirx * SPEED;
		data->cam_state.posy += data->cam_state.diry * SPEED;
	}
	if (keycode == S_KEY && check_wall(data, keycode))
	{
		data->cam_state.posx -= data->cam_state.dirx * SPEED;
		data->cam_state.posy -= data->cam_state.diry * SPEED;
	}
	if (keycode == D_KEY && check_wall(data, keycode))
	{
		data->cam_state.posx -= data->cam_state.diry * SPEED;
		data->cam_state.posy += data->cam_state.dirx * SPEED;
	}
	if (keycode == A_KEY && check_wall(data, keycode))
	{
		data->cam_state.posx += data->cam_state.diry * SPEED;
		data->cam_state.posy -= data->cam_state.dirx * SPEED;
	}
	if (keycode == P_KEY)
	{
		data->p *= -1;
		if (data->p < 0)
			mlx_mouse_show(data->mlx, data->win);
		else
			mlx_mouse_hide(data->mlx, data->win);
	}

	rotator(keycode, data);
	if (keycode == ESC)
		super_exit(data);
	return (0);
}
