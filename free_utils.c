/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:25:33 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/26 20:32:44 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*texture_cleaner(char *orig)
{
	int		i;
	char	*txt;

	i = 0;
	txt = orig + 2;
	while (txt[i] && txt[i] == ' ')
		i++;
	if (txt[i])
	{
		txt += i;
		i = 0;
		while (txt[i])
			i++;
		i--;
		if (i >= 0)
			txt[i] = '\0';
	}
	txt = ft_strdup(txt);
	/* free (orig); */
	return (txt);
}

void	ft_free_all_map(char **all_map)
{
	int	i;

	i = 0;
	while (all_map[i])
	{
		free(all_map[i]);
		i++;
	}
	free(all_map[i]);
}

int	super_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}
