/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:41:25 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/29 15:44:58 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_characters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == '1'\
			|| data->map[i][j] == 'D' \
			|| data->map[i][j] == 'O' || data->map[i][j] == 'W' \
			|| data->map[i][j] == 'E' || \
			data->map[i][j] == 'S' || data->map[i][j] == 'N' \
			|| data->map[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_map_manager(t_data *data)
{
	if (check_characters(data))
		return (1);
	if (check_wall(data))
		return (1);
	return (0);
}
