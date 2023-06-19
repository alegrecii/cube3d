/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:17:59 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/19 16:40:14 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_setter_helper(char c, t_cam *cam)
{
	if (c == 'E')
	{
		cam->dirx = 1;
		cam->diry = 0;
		cam->camx = 0;
		cam->camy = FOV;
	}
	if (c == 'O')
	{
		cam->dirx = -1;
		cam->diry = 0;
		cam->camx = 0;
		cam->camy = FOV;
	}
}

int	cam_setter(char c, int y, int x, t_cam *cam)
{
	cam->posx = x;
	cam->posy = y;
	if (c == 'N')
	{
		cam->dirx = 0;
		cam->diry = -1;
		cam->camx = FOV;
		cam->camy = 0;
	}
	if (c == 'S')
	{
		cam->dirx = 0;
		cam->diry = 1;
		cam->camx = FOV;
		cam->camy = 0;
	}
	cam_setter_helper(c, cam);
	return (0);
}

int	cam_init(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NSWE", data->map[y][x]))
				return (cam_setter(data->map[y][x], y, x, &data->cam_state));
			x++;
		}
		y++;
	}
	return (1);
}

int	check_arg(char **str)
{
	int	i;

	i = 0;
	while (str[1][i])
	{
		if (str[1][i] == '.' && str[1][i + 1] == 'c' && \
		str[1][i + 2] == 'u' && str[1][i + 3] == 'b' && str[1][i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}
