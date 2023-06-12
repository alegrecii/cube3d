/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:02:44 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/12 19:03:45 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_data *data, char **argv)
{
	//init_data(data);
	data->path = argv[1];
	map_conversion(data);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		if (check_arg(argv))
			return (write(1, "Error: Map error\n", 17));
		else
			init_game(&data, argv);
	}
	else
		return (write(2, "Error: Bad arguments\n", 21));
}
