/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:34:30 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/12 20:45:43 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->fc_color = malloc(sizeof(char *) * 2);
	data->fc_color[2] = NULL;
	save_floor_color(data, all_map);
	save_ceiling_color(data, all_map);
}
