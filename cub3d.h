/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:00:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/12 20:38:18 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "Get_Next_Line/get_next_line.h"
# include <sys/types.h>

typedef struct s_data
{
	char	*path;
	char	**map;
	char	**path_text;
	char	**fc_color;
}		t_data;

int		check_arg(char **str);
void	map_conversion(t_data *data);
void	ft_free_all_map(char **all_map);
void	save_path_text(t_data *data, char **all_map);
void	save_fc_color(t_data *data, char **all_map);

#endif

