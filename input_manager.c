/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:32:44 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/21 17:15:03 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotator(int keycode, t_data *data)
{
	double	dirx;
	double	camx;

	camx = data->cam_state.camx;
	dirx = data->cam_state.dirx;

	if (keycode == ARROW_LEFT)
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
	if (keycode == ARROW_RIGHT)
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
	if (keycode == W_KEY)
	{
		data->cam_state.posx += data->cam_state.dirx * SPEED;
		data->cam_state.posy += data->cam_state.diry * SPEED;
	}
	if (keycode == S_KEY)
	{
		data->cam_state.posx -= data->cam_state.dirx * SPEED;
		data->cam_state.posy -= data->cam_state.diry * SPEED;
	}
	if (keycode == D_KEY)
	{
		data->cam_state.posx -= data->cam_state.diry * SPEED;
		data->cam_state.posy += data->cam_state.dirx * SPEED;
	}
	if (keycode == A_KEY)
	{
		data->cam_state.posx += data->cam_state.diry * SPEED;
		data->cam_state.posy -= data->cam_state.dirx * SPEED;
	}
	rotator(keycode, data);
	printf("x :%f, y:%f\n", data->cam_state.posx, data->cam_state.posy);
	if (keycode == ESC)
		super_exit(data);
	return (0);
}
