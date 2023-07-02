/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:34:30 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/02 16:50:17 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	unsigned int	hex;

	hex = r * 65536 + g * 256 + b;
	return (hex);
}

void	color_converter(t_data *data)
{
	char	**ceiling;
	char	**floor;

	ceiling = ft_split(data->fc_color[1], ',');
	floor = ft_split(data->fc_color[0], ',');
	data->ceiling = rgb_to_hex(ft_atoi(ceiling[0] + 2), \
	ft_atoi(ceiling[1]), ft_atoi(ceiling[2]));
	data->floor = rgb_to_hex(ft_atoi(floor[0] + 2), \
	ft_atoi(floor[1]), ft_atoi(floor[2]));
	ft_free_all_map(ceiling);
	ft_free_all_map(floor);
	free(ceiling);
	free(floor);
}

void	save_ceiling_color(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == 'C' && all_map[i][j + 1] == ' ')
			{
				data->fc_color[1] = all_map[i];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	save_floor_color(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == 'F' && all_map[i][j + 1] == ' ')
			{
				data->fc_color[0] = all_map[i];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	save_fc_color(t_data *data, char **all_map)
{
	data->fc_color = malloc(sizeof(char *) * 3);
	data->fc_color[2] = NULL;
	save_floor_color(data, all_map);
	save_ceiling_color(data, all_map);
	color_converter(data);
}
