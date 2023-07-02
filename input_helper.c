/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:45:18 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/02 18:51:17 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotator_helper(t_data *data, double dirx, double camx)
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

int	check_wall_helper(t_data *data, int keycode, int wall_dist)
{
	if (keycode == W_KEY && data->map[(int)(data->cam_state.posy + \
	data->cam_state.diry * (SPEED + wall_dist))][(int)(\
	data->cam_state.posx + data->cam_state.dirx * (SPEED + wall_dist))] == 'D')
		return (0);
	if (keycode == S_KEY && data->map[(int)(data->cam_state.posy - \
	data->cam_state.diry * (SPEED + wall_dist))][(int)(\
	data->cam_state.posx - data->cam_state.dirx * (SPEED + wall_dist))] == 'D')
		return (0);
	if (keycode == D_KEY && data->map[(int)(data->cam_state.posy + \
	data->cam_state.dirx * (SPEED + wall_dist))][(int)(\
	data->cam_state.posx - data->cam_state.diry * (SPEED + wall_dist))] == 'D')
		return (0);
	if (keycode == A_KEY && data->map[(int)(data->cam_state.posy - \
	data->cam_state.dirx * (SPEED + wall_dist))][(int)(\
	data->cam_state.posx + data->cam_state.diry * (SPEED + wall_dist))] == 'D')
		return (0);
	return (1);
}

int	open_door_helper(t_data *data, int opened)
{
	if (data->map[(int)data->cam_state.posy][(int)data->cam_state.posx \
	+ 1] == 'D')
	{
		data->map[(int)data->cam_state.posy][(int)data->cam_state.posx \
		+ 1] = 'O';
		opened = 1;
	}
	if (data->map[(int)data->cam_state.posy][(int)data->cam_state.posx \
	- 1] == 'D')
	{
		data->map[(int)data->cam_state.posy][(int)data->cam_state.posx \
		- 1] = 'O';
		opened = 1;
	}
	return (opened);
}

void	p_esc_keys(int keycode, t_data *data)
{
	if (keycode == P_KEY)
	{
		data->p *= -1;
	}
	if (keycode == ESC)
		super_exit(data);
}
