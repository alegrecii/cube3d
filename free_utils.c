/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:25:33 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/30 16:23:15 by alegreci         ###   ########.fr       */
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
	/* free (orig); */
	return (txt);
}

void	ft_free_all_map(char **all_map)
{
	int	i;

	i = 0;
	while (all_map[i])
	{
		free(all_map[i]);
		i++;
	}
	free(all_map[i]);
}

int	super_exit(t_data *data)
{
	int	i;

	i = 0;

	mlx_destroy_image(data->mlx, data->no.img);
	mlx_destroy_image(data->mlx, data->so.img);
	mlx_destroy_image(data->mlx, data->ea.img);
	mlx_destroy_image(data->mlx, data->we.img);
	mlx_destroy_image(data->mlx, data->screen.img);
	mlx_destroy_image(data->mlx, data->door.img);
	while (i < 19)
	{
		mlx_destroy_image(data->mlx, data->fire[i].img);
		i++;
	}
	free(data->fire);
	ft_free_all_map(data->map);
	free (data->map);
	free(data->fc_color);
	i = 0;
	while (i < 5)
		free(data->path_text[i++]);
	free (data->path_text);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
