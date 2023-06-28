/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:35:40 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/28 20:02:20 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_fire(t_data *data)
{
	data->fire = malloc(sizeof (t_img) * 19);
	texture_init(data, "textures/fire/f1.xpm", &data->fire[0]);
	texture_init(data, "textures/fire/f2.xpm", &data->fire[1]);
	texture_init(data, "textures/fire/f3.xpm", &data->fire[2]);
	texture_init(data, "textures/fire/f4.xpm", &data->fire[3]);
	texture_init(data, "textures/fire/f5.xpm", &data->fire[4]);
	texture_init(data, "textures/fire/f6.xpm", &data->fire[5]);
	texture_init(data, "textures/fire/f7.xpm", &data->fire[6]);
	texture_init(data, "textures/fire/f8.xpm", &data->fire[7]);
	texture_init(data, "textures/fire/f9.xpm", &data->fire[8]);
	texture_init(data, "textures/fire/f10.xpm", &data->fire[9]);
	texture_init(data, "textures/fire/f11.xpm", &data->fire[10]);
	texture_init(data, "textures/fire/f12.xpm", &data->fire[11]);
	texture_init(data, "textures/fire/f13.xpm", &data->fire[12]);
	texture_init(data, "textures/fire/f14.xpm", &data->fire[13]);
	texture_init(data, "textures/fire/f15.xpm", &data->fire[14]);
	texture_init(data, "textures/fire/f16.xpm", &data->fire[15]);
	texture_init(data, "textures/fire/f17.xpm", &data->fire[16]);
	texture_init(data, "textures/fire/f18.xpm", &data->fire[17]);
	texture_init(data, "textures/fire/f19.xpm", &data->fire[18]);
}

void	animation_manager(t_data *data)
{
	static int	i = 1;
	int	color;
	int	x;
	int	y;
	int posy = 100;
	int	posx;

	y = 0;
	color = 0;
	while (y < 1100)
	{
		x = 0;
		posx = 100;
		while (x < 1100)
		{
			color = *(int *)(data->fire[0].addr + (4 * data->fire[0].w * x) + (4 * y));
			if (color >= 0)
				my_mlx_pixel_put(&data->screen, posy, posx,color);
			posx++;
			x++;
		}
		y++;
		posy++;
	}
	//i++;
	if (i >= 19)
		i = 1;
}
