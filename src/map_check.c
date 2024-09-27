/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:30:29 by nicleena          #+#    #+#             */
/*   Updated: 2024/09/26 17:59:09 by nicleena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_after_back(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_free_tab(map);
				error_msg_free_tab("Error\nMap is not solvable\n",
					data->map.map_data);
			}
			x++;
		}
		y++;
	}
}

void	check_tile(t_data *data, char tile, int x, int y)
{
	if (tile == 'P')
	{
		data->map.p_count++;
		data->map.x_player = x;
		data->map.y_player = y;
	}
	else if (tile == 'E')
		data->map.e_count++;
	else if (tile == 'C')
		data->map.c_count++;
}

void	count_objects(t_data *data)
{
	int		x;
	int		y;
	char	tile;

	data->map.p_count = 0;
	data->map.e_count = 0;
	data->map.c_count = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			tile = data->map.map_data[y][x];
			check_tile(data, tile, x, y);
			x++;
		}
		y++;
	}
	if (data->map.p_count != 1 || data->map.e_count != 1
		|| data->map.c_count < 1)
		error_msg_free_tab("Error\nMap invalid\n", data->map.map_data);
}

void	back_tracking(char **map, int y, int x)
{
	map[y][x] = 'G';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'G')
		back_tracking(map, y + 1, x);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'G')
		back_tracking(map, y - 1, x);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'G')
		back_tracking(map, y, x + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'G')
		back_tracking(map, y, x - 1);
}
