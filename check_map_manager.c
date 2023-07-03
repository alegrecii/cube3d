/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:41:25 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/03 12:19:34 by alegreci         ###   ########.fr       */
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
			|| data->map[i][j] == 'D' || data->map[i][j] == 'O' \
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
	fill_first_last_help(check_map, data, len, count);
	return (count + 2);
}

void	fill_check(char **check_map, t_data *data, int max)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		check_map[i + 1][0] = 'e';
		while (data->map[i][j])
		{
			if (data->map[i][j] != '\n')
				check_map[i + 1][j + 1] = data->map[i][j];
			else
				check_map[i + 1][j + 1] = ' ';
			j++;
		}
		while (j + 1 < max)
			check_map[i + 1][j++ + 1] = 'e';
		check_map[i + 1][j + 1] = '\n';
		check_map[i + 1][j + 2] = '\0';
		i++;
	}
	check_map[i + 2] = NULL;
	check_space_wall(check_map);
}

int	check_wall_map(t_data *data)
{
	char	**check_map;

	data->flood_check = 0;
	check_map = ft_calloc(sizeof(char *), (counter_map(data->map, 0) + 3));
	fill_check(check_map, data, fill_first_last(check_map, data));
	flood_fill(data, check_map, 0, 0);
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
