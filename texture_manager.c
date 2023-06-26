/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:59:55 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/26 15:00:39 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*texture_cleaner(char *orig)
{
	int		i;
	char	*txt;

	i = 0;
	txt = orig + 2;
	while (txt[i] && txt[i] == ' ')
		i++;
	if (txt[i])
	{
		txt += i;
		i = 0;
		while (txt[i])
			i++;
		i--;
		if (i >= 0)
			txt[i] = '\0';
	}
	txt = ft_strdup(txt);
	free (orig);
	return (txt);
}

void	texture_chooser(t_ray *ray, t_img *screen, int col, int y)
{
	if (ray->side == 0 && ray->dirx > 0) //E
		my_mlx_pixel_put(screen, col, y, 457474);
	if (ray->side == 0 && ray->dirx < 0) //W
		my_mlx_pixel_put(screen, col, y, 346346);
	if (ray->side == 1 && ray->diry > 0) //S
		my_mlx_pixel_put(screen, col, y, 745745);
	if (ray->side == 1 && ray->diry < 0) //N
		my_mlx_pixel_put(screen, col, y, 567546);
}
