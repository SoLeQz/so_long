/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:29:53 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 18:00:12 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_lines_width(t_data *data)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(data->map.map_data[0]);
	while (data->map.map_data[i])
	{
		if ((int)ft_strlen(data->map.map_data[i]) != width)
			error_msg_free_tab("Error\nMap should be a square or rectangle\n",
				data->map.map_data);
		i++;
	}
	data->map.width = width;
}

void	check_horizontal_walls(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->map.width)
	{
		if (data->map.map_data[0][x] != '1'
			|| data->map.map_data[data->map.height - 1][x] != '1')
			error_msg_free_tab("Error\nMap must be surrounded by walls\n",
				data->map.map_data);
		x++;
	}
}

void	check_vertical_walls(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		if (data->map.map_data[y][0] != '1'
			|| data->map.map_data[y][data->map.width - 1] != '1')
			error_msg_free_tab("Error\nMap must be surrounded by walls\n",
				data->map.map_data);
		y++;
	}
}

void	check_wall(t_data *data)
{
	check_horizontal_walls(data);
	check_vertical_walls(data);
}

void	check_if_finishable(t_data *data)
{
	char	**map_copy;

	map_copy = tab_dup(data->map.map_data, data->map.height);
	if (!map_copy)
		error_msg_free_tab("Error\nFailed to duplicate map\n",
			data->map.map_data);
	back_tracking(map_copy, data->map.y_player, data->map.x_player);
	check_after_back(data, map_copy);
	ft_free_tab(map_copy);
}
