/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:45:18 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/03 12:50:34 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		data->p *= -1;
	if (keycode == ESC)
		super_exit(data);
}

//funzione che perde memoria, ma piu' carina;
/* void	p_esc_keys(int keycode, t_data *data)
{
	if (keycode == P_KEY)
	{
		data->p *= -1;
		if (data->p < 0)
			mlx_mouse_show(data->mlx, data->win);
		else
			mlx_mouse_hide(data->mlx, data->win);
	}
	if (keycode == ESC)
		super_exit(data);
} */
