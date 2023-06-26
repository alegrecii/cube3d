/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:59:18 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/26 17:12:35 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_starter(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, input_manager, data);
	mlx_loop_hook(data->mlx, updater, data);
	mlx_hook(data->win, 17, 0, super_exit, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	mlx_loop(data->mlx);
}
