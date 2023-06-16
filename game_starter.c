/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:59:18 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/16 17:02:41 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_starter(t_data *data)
{
	mlx_key_hook(data->win, input_manager, data);
	mlx_loop_hook(data->mlx, updater, data);
	mlx_hook(data->win, 17, 0, super_exit, data);
	mlx_loop(data->mlx);
}
