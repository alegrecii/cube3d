/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:25:14 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/03 12:52:50 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_mouse_left(t_data *data)
{
	double	dirx;
	double	camx;

	camx = data->cam_state.camx;
	dirx = data->cam_state.dirx;
	data->cam_state.dirx = data->cam_state.dirx * \
	cos(-ROT_MOUSE) - data->cam_state.diry * sin(-ROT_MOUSE);
	data->cam_state.diry = dirx * sin(-ROT_MOUSE) + \
	data->cam_state.diry * cos(-ROT_MOUSE);
	data->cam_state.camx = data->cam_state.camx * \
	cos(-ROT_MOUSE) - data->cam_state.camy * sin(-ROT_MOUSE);
	data->cam_state.camy = camx * sin(-ROT_MOUSE) + \
	data->cam_state.camy * cos(-ROT_MOUSE);
}

void	move_mouse_right(t_data *data)
{
	double	dirx;
	double	camx;

	camx = data->cam_state.camx;
	dirx = data->cam_state.dirx;
	data->cam_state.dirx = data->cam_state.dirx * \
	cos(ROT_MOUSE) - data->cam_state.diry * sin(ROT_MOUSE);
	data->cam_state.diry = dirx * sin(ROT_MOUSE) + \
	data->cam_state.diry * cos(ROT_MOUSE);
	data->cam_state.camx = data->cam_state.camx * \
	cos(ROT_MOUSE) - data->cam_state.camy * sin(ROT_MOUSE);
	data->cam_state.camy = camx * sin(ROT_MOUSE) + \
	data->cam_state.camy * cos(ROT_MOUSE);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (x > WIDTH / 2 && data->p > 0)
		move_mouse_right(data);
	else if (x < WIDTH / 2 && data->p > 0)
		move_mouse_left(data);
	(void)y;
	return (0);
}
