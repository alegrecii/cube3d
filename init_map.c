/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:58:29 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/12 19:06:34 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void

void	map_conversion(t_data *data)
{
	int	i;
	int	fd;
	char **all_map;

	i = 0;

	counter_map(data);
	fd = open(data->path);
	while (all_map[i])
}
