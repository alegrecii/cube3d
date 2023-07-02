/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:59:18 by alegreci          #+#    #+#             */
/*   Updated: 2023/07/02 16:53:09 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_conversion_helper(t_data *data, char **all_map, int fd)
{
	save_map(data, all_map);
	save_path_text(data, all_map);
	save_fc_color(data, all_map);
	close(fd);
	ft_free_all_map(all_map);
	free (all_map);
}

void	game_starter(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, input_manager, data);
	mlx_loop_hook(data->mlx, updater, data);
	mlx_hook(data->win, 17, 0, super_exit, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	mlx_loop(data->mlx);
}
