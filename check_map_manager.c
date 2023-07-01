/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:41:25 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/01 01:48:18 by alegreci         ###   ########.fr       */
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
		if (data->map[i][j] == '\0' || data->map[i][j] == '\n')
			return (1);
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == '1'\
			|| data->map[i][j] == 'D'|| data->map[i][j] == 'O' \
			|| data->map[i][j] == '\n' || data->map[i][j] == ' ')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	fill_first_last(char **check_map, t_data *data)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	len = counter_map(data->map, 0) + 1;
	count = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (count < (int)ft_strlen(data->map[i]))
			count = ft_strlen(data->map[i]);
		i++;
	}
	i = 0;
	while (i <= len)
	{
		check_map[i] = ft_calloc(sizeof(char), (count + 4));
		i++;
	}
	i = 1;
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
	return (count + 2);
}

void	fill_check(char **check_map, t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	max;

	i = 0;
	j = 0;
	x = 1;
	max = fill_first_last(check_map, data);
	while (data->map[i])
	{
		j = 0;
		y = 1;
		check_map[x][0] = 'e';
		while (data->map[i][j])
		{
			if (data->map[i][j] != '\n')
			{
				check_map[x][y] = data->map[i][j];
				y++;
				j++;
			}
			else
			{
				check_map[x][y] = ' ';
				y++;
				j++;
			}
		}
		while (y < max)
		{
			check_map[x][y] = 'e';
			y++;
		}
		check_map[x][y] = '\n';
		check_map[x][y + 1] = '\0';
		i++;
		x++;
	}
	check_map[x + 1] = NULL;
	check_space_wall(check_map);
}

int	check_wall_map(t_data *data)
{
	char	**check_map;

	data->flood_check = 0;
	check_map = ft_calloc(sizeof(char *), (counter_map(data->map, 0) + 3));
	fill_check(check_map, data);
	flood_fill(data, check_map, 0, 0);
/* 	int	i = 0;
	while (check_map[i])
	{
		printf("%s", check_map[i]);
		i++;
	} */
	ft_free_all_map(check_map);
	free(check_map);
	if (data->flood_check)
		return (1);
	return (0);
}

int	check_map_manager(t_data *data)
{
	if (check_characters(data))
		return (1);
	if (check_wall_map(data))
		return (1);
	return (0);
}
