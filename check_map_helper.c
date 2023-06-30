/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:50:55 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/30 19:25:57 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_space_wall(char **check_map)
{
	int	i;
	int	j;

	i = 0;
	while (check_map[i])
	{
		j = 0;
		while (check_map[i][j])
		{
			if (check_map[i][j] == ' ')
				check_map[i][j] = 'e';
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *data, char **map, int row, int col)
{
	if (!map[row] || map[row][col] == '1' || map[row][col] == '\n' || !map[row][col])
		return ;
	if (map[row][col] != '1' && map[row][col] != 'e' && map[row][col] != 'y')
		data->flood_check = 1;
	map[row][col] = '1';
	if (row > 0)
		flood_fill(data, map, row -1, col);
	flood_fill(data, map, row +1, col);
	if (col > 0)
		flood_fill(data, map, row, col - 1);
	flood_fill(data, map, row, col + 1);
}
