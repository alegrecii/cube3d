/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:32:44 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/30 15:03:28 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_door(t_data *data)
{
	if (data->map[(int)data->cam_state.posy + 1][(int)data->cam_state.posx] == 'O')
		data->map[(int)data->cam_state.posy + 1][(int)data->cam_state.posx] = 'D';
	if (data->map[(int)data->cam_state.posy - 1][(int)data->cam_state.posx] == 'O')
		data->map[(int)data->cam_state.posy - 1][(int)data->cam_state.posx] = 'D';
	if (data->map[(int)data->cam_state.posy][(int)data->cam_state.posx + 1] == 'O')
		data->map[(int)data->cam_state.posy][(int)data->cam_state.posx + 1] = 'D';
	if (data->map[(int)data->cam_state.posy][(int)data->cam_state.posx - 1] == 'O')
		data->map[(int)data->cam_state.posy][(int)data->cam_state.posx - 1] = 'D';
}

void	open_door(t_data *data)
{
	int	opened;

	opened = 0;
	if (data->map[(int)data->cam_state.posy + 1][(int)data->cam_state.posx] == 'D')
	{
		data->map[(int)data->cam_state.posy + 1][(int)data->cam_state.posx] = 'O';
		opened = 1;
	}
	if (data->map[(int)data->cam_state.posy - 1][(int)data->cam_state.posx] == 'D')
	{
		data->map[(int)data->cam_state.posy - 1][(int)data->cam_state.posx] = 'O';
		opened = 1;
	}
	if (data->map[(int)data->cam_state.posy][(int)data->cam_state.posx + 1] == 'D')
	{
		data->map[(int)data->cam_state.posy][(int)data->cam_state.posx + 1] = 'O';
		opened = 1;
	}
	if (data->map[(int)data->cam_state.posy][(int)data->cam_state.posx - 1] == 'D')
	{
		data->map[(int)data->cam_state.posy][(int)data->cam_state.posx - 1] = 'O';
		opened = 1;
	}
	if (opened == 0)
		close_door(data);
}

int	check_wall(t_data *data, int keycode)
{
	double wall_dist;

	wall_dist = 0.1;
	if (keycode == W_KEY && data->map[(int)(data->cam_state.posy + data->cam_state.diry * (SPEED + wall_dist))][(int)(data->cam_state.posx + data->cam_state.dirx * (SPEED + wall_dist))] == '1')
		return(0);
	if (keycode == S_KEY && data->map[(int)(data->cam_state.posy - data->cam_state.diry * (SPEED + wall_dist))][(int)(data->cam_state.posx - data->cam_state.dirx * (SPEED + wall_dist))] == '1')
		return(0);
	if (keycode == D_KEY && data->map[(int)(data->cam_state.posy + data->cam_state.dirx * (SPEED + wall_dist))][(int)(data->cam_state.posx - data->cam_state.diry * (SPEED + wall_dist))] == '1')
		return(0);
	if (keycode == A_KEY && data->map[(int)(data->cam_state.posy - data->cam_state.dirx * (SPEED + wall_dist))][(int)(data->cam_state.posx + data->cam_state.diry * (SPEED + wall_dist))] == '1')
		return(0);
	if (keycode == W_KEY && data->map[(int)(data->cam_state.posy + data->cam_state.diry * (SPEED + wall_dist))][(int)(data->cam_state.posx + data->cam_state.dirx * (SPEED + wall_dist))] == 'D')
		return(0);
	if (keycode == S_KEY && data->map[(int)(data->cam_state.posy - data->cam_state.diry * (SPEED + wall_dist))][(int)(data->cam_state.posx - data->cam_state.dirx * (SPEED + wall_dist))] == 'D')
		return(0);
	if (keycode == D_KEY && data->map[(int)(data->cam_state.posy + data->cam_state.dirx * (SPEED + wall_dist))][(int)(data->cam_state.posx - data->cam_state.diry * (SPEED + wall_dist))] == 'D')
		return(0);
	if (keycode == A_KEY && data->map[(int)(data->cam_state.posy - data->cam_state.dirx * (SPEED + wall_dist))][(int)(data->cam_state.posx + data->cam_state.diry * (SPEED + wall_dist))] == 'D')
		return(0);
	return(1);
}

int	rotator(int keycode, t_data *data)
{
	double	dirx;
	double	camx;

	camx = data->cam_state.camx;
	dirx = data->cam_state.dirx;

	if (keycode == ARROW_RIGHT)
	{
		data->cam_state.dirx = data->cam_state.dirx * cos(ROT) - data->cam_state.diry * sin(ROT);
		data->cam_state.diry = dirx * sin(ROT) + data->cam_state.diry * cos(ROT);
		data->cam_state.camx = data->cam_state.camx * cos(ROT) - data->cam_state.camy * sin(ROT);
		data->cam_state.camy = camx * sin(ROT) + data->cam_state.camy * cos(ROT);
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
	return (0);
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
	if (keycode == E_KEY)
		open_door(data);
	rotator(keycode, data);
	p_esc_key(keycode, data);
	return (0);
}
