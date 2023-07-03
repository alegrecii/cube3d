/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:50:55 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/03 12:04:28 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_first_last_help(char **check_map, t_data *data, int len, int count)
{
	int	i;

	i = 0;
	(void)data;
	check_map[0][0] = 'y';
	check_map[len][0] = 'e';
	while (i < (count + 2))
	{
		check_map[0][i] = 'e';
		check_map[len][i] = 'e';
		i++;
	}
	check_map[0][i] = '\n';
	check_map[len][i] = '\n';
	check_map[0][i + 1] = '\0';
	check_map[len][i + 1] = '\0';
}

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
	if (!map[row] || map[row][col] == '1' \
	|| map[row][col] == '\n' || !map[row][col])
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
